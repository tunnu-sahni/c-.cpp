import sqlite3
from werkzeug.security import generate_password_hash

DB_NAME = "college.db"


def get_connection():
    conn = sqlite3.connect(DB_NAME)
    conn.row_factory = sqlite3.Row
    return conn


def init_db():

    conn = get_connection()
    cursor = conn.cursor()

    # Users table
    cursor.execute("""
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            email TEXT UNIQUE NOT NULL,
            password TEXT NOT NULL,
            role TEXT DEFAULT 'student'
        )
    """)

    # Notices table
    cursor.execute("""
        CREATE TABLE IF NOT EXISTS notices (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            title TEXT NOT NULL,
            content TEXT NOT NULL
        )
    """)

    # Courses table
    cursor.execute("""
        CREATE TABLE IF NOT EXISTS courses (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            duration TEXT NOT NULL,
            description TEXT
        )
    """)

    # Faculty table
    cursor.execute("""
        CREATE TABLE IF NOT EXISTS faculty (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            subject TEXT NOT NULL,
            email TEXT
        )
    """)

    # Timetable table
    cursor.execute("""
        CREATE TABLE IF NOT EXISTS timetable (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            day TEXT NOT NULL,
            subject TEXT NOT NULL,
            time TEXT NOT NULL
        )
    """)

    # Create admin account
    admin = cursor.execute(
        "SELECT * FROM users WHERE email=?",
        ("admin@college.com",)
    ).fetchone()

    if not admin:

        cursor.execute(
            """
            INSERT INTO users
            (name, email, password, role)
            VALUES (?, ?, ?, ?)
            """,
            (
                "College Admin",
                "admin@college.com",
                generate_password_hash("admin123"),
                "admin"
            )
        )

    # Sample notices
    if cursor.execute(
        "SELECT COUNT(*) FROM notices"
    ).fetchone()[0] == 0:

        notices = [
            (
                "Semester Examination",
                "Semester examination will start from 10 September."
            ),
            (
                "Project Submission",
                "Final year project submission deadline is 25 September."
            ),
            (
                "Holiday Notice",
                "College will remain closed on the upcoming public holiday."
            )
        ]

        cursor.executemany(
            "INSERT INTO notices (title, content) VALUES (?, ?)",
            notices
        )

    # Sample courses
    if cursor.execute(
        "SELECT COUNT(*) FROM courses"
    ).fetchone()[0] == 0:

        courses = [
            (
                "BCA",
                "3 Years",
                "Bachelor of Computer Applications"
            ),
            (
                "BBA",
                "3 Years",
                "Bachelor of Business Administration"
            ),
            (
                "B.Tech Computer Science",
                "4 Years",
                "Computer Science and Engineering"
            )
        ]

        cursor.executemany(
            """
            INSERT INTO courses
            (name, duration, description)
            VALUES (?, ?, ?)
            """,
            courses
        )

    # Sample faculty
    if cursor.execute(
        "SELECT COUNT(*) FROM faculty"
    ).fetchone()[0] == 0:

        faculty = [
            (
                "Dr. Rahul Sharma",
                "Python",
                "rahul@college.com"
            ),
            (
                "Dr. Priya Singh",
                "Database",
                "priya@college.com"
            ),
            (
                "Mr. Amit Kumar",
                "Data Structures",
                "amit@college.com"
            )
        ]

        cursor.executemany(
            """
            INSERT INTO faculty
            (name, subject, email)
            VALUES (?, ?, ?)
            """,
            faculty
        )

    # Sample timetable
    if cursor.execute(
        "SELECT COUNT(*) FROM timetable"
    ).fetchone()[0] == 0:

        timetable = [
            ("Monday", "Python", "10:00 AM"),
            ("Monday", "Data Structures", "12:00 PM"),
            ("Tuesday", "Database", "10:00 AM"),
            ("Tuesday", "Computer Networks", "12:00 PM"),
            ("Wednesday", "Web Development", "10:00 AM"),
            ("Thursday", "Python Lab", "11:00 AM"),
            ("Friday", "DSA Lab", "11:00 AM")
        ]

        cursor.executemany(
            """
            INSERT INTO timetable
            (day, subject, time)
            VALUES (?, ?, ?)
            """,
            timetable
        )

    conn.commit()
    conn.close()

from flask import Flask, render_template, request, redirect, url_for, session, jsonify
from werkzeug.security import generate_password_hash, check_password_hash


app = Flask(__name__)
app.secret_key = "college_assistant_secret_key"

init_db()


# ---------------- HOME ----------------

@app.route("/")
def home():
    return render_template("index.html")


# ---------------- REGISTER ----------------

@app.route("/register", methods=["GET", "POST"])
def register():

    if request.method == "POST":

        name = request.form["name"]
        email = request.form["email"]
        password = request.form["password"]

        conn = get_connection()

        existing = conn.execute(
            "SELECT * FROM users WHERE email=?",
            (email,)
        ).fetchone()

        if existing:
            conn.close()
            return "Email already registered!"

        hashed_password = generate_password_hash(password)

        conn.execute(
            "INSERT INTO users (name,email,password) VALUES (?,?,?)",
            (name, email, hashed_password)
        )

        conn.commit()
        conn.close()

        return redirect(url_for("login"))

    return render_template("register.html")


# ---------------- LOGIN ----------------

@app.route("/login", methods=["GET", "POST"])
def login():

    if request.method == "POST":

        email = request.form["email"]
        password = request.form["password"]

        conn = get_connection()

        user = conn.execute(
            "SELECT * FROM users WHERE email=?",
            (email,)
        ).fetchone()

        conn.close()

        if user and check_password_hash(user["password"], password):

            session["user_id"] = user["id"]
            session["name"] = user["name"]
            session["role"] = user["role"]

            if user["role"] == "admin":
                return redirect(url_for("admin"))

            return redirect(url_for("dashboard"))

        return "Invalid email or password!"

    return render_template("login.html")


# ---------------- DASHBOARD ----------------

@app.route("/dashboard")
def dashboard():

    if "user_id" not in session:
        return redirect(url_for("login"))

    conn = get_connection()

    notices = conn.execute(
        "SELECT * FROM notices ORDER BY id DESC"
    ).fetchall()

    courses = conn.execute(
        "SELECT * FROM courses"
    ).fetchall()

    faculty = conn.execute(
        "SELECT * FROM faculty"
    ).fetchall()

    timetable = conn.execute(
        "SELECT * FROM timetable"
    ).fetchall()

    conn.close()

    return render_template(
        "dashboard.html",
        name=session["name"],
        notices=notices,
        courses=courses,
        faculty=faculty,
        timetable=timetable
    )


# ---------------- CHATBOT ----------------

@app.route("/chat", methods=["POST"])
def chat():

    data = request.get_json()
    message = data.get("message", "").lower()

    if "hello" in message or "hi" in message:
        response = "Hello! I am your College Assistant. How can I help you?"

    elif "course" in message or "courses" in message:
        response = (
            "Our college offers BCA, BBA and B.Tech Computer Science. "
            "You can see complete course details on the dashboard."
        )

    elif "bca" in message:
        response = (
            "BCA is a 3-year undergraduate computer application program. "
            "It covers programming, databases, web development and computer science."
        )

    elif "exam" in message:
        response = (
            "The sample semester examination notice says examinations "
            "will start from 10 September. Please verify the official notice."
        )

    elif "timetable" in message or "schedule" in message:
        response = (
            "Your timetable is available in the dashboard. "
            "You can check subjects and class timings there."
        )

    elif "faculty" in message or "teacher" in message:
        response = (
            "Faculty information is available in the Faculty section "
            "of your dashboard."
        )

    elif "project" in message:
        response = (
            "The project submission deadline in the sample notice is "
            "25 September."
        )

    elif "fee" in message or "fees" in message:
        response = (
            "For fee-related information, please contact the college "
            "accounts department."
        )

    elif "attendance" in message:
        response = (
            "Please check your student portal or contact your department "
            "for official attendance information."
        )

    elif "thank" in message:
        response = "You're welcome! 😊"

    else:
        response = (
            "I am currently using the college knowledge base. "
            "Try asking about courses, BCA, exams, timetable, faculty, "
            "projects, fees or attendance."
        )

    return jsonify({"response": response})


# ---------------- ADMIN ----------------

@app.route("/admin")
def admin():

    if session.get("role") != "admin":
        return "Access denied!"

    conn = get_connection()

    notices = conn.execute(
        "SELECT * FROM notices ORDER BY id DESC"
    ).fetchall()

    conn.close()

    return render_template("admin.html", notices=notices)


@app.route("/add_notice", methods=["POST"])
def add_notice():

    if session.get("role") != "admin":
        return "Access denied!"

    title = request.form["title"]
    content = request.form["content"]

    conn = get_connection()

    conn.execute(
        "INSERT INTO notices (title,content) VALUES (?,?)",
        (title, content)
    )

    conn.commit()
    conn.close()

    return redirect(url_for("admin"))


@app.route("/delete_notice/<int:notice_id>")
def delete_notice(notice_id):

    if session.get("role") != "admin":
        return "Access denied!"

    conn = get_connection()

    conn.execute(
        "DELETE FROM notices WHERE id=?",
        (notice_id,)
    )

    conn.commit()
    conn.close()

    return redirect(url_for("admin"))


# ---------------- LOGOUT ----------------

@app.route("/logout")
def logout():

    session.clear()

    return redirect(url_for("home"))



from flask import Flask, render_template, request, redirect, url_for, session, jsonify
from werkzeug.security import generate_password_hash, check_password_hash

app = Flask(__name__)

app.secret_key = "college_assistant_secret_key"

init_db()


# =========================
# HOME
# =========================

# tumhare existing routes...


# =========================
# AUTHENTICATION
# =========================

# login route
# register route
# logout route


# =========================
# DASHBOARD
# =========================

# dashboard route


# =========================
# COLLEGE FEATURES
# =========================

@app.route("/chatbot", methods=["GET", "POST"])
def chatbot():

    answer = None
    question = ""

    if request.method == "POST":

        question = request.form.get("question", "").strip().lower()

        if "admission" in question:
            answer = "Admission ke liye college admission office se contact karein."

        elif "exam" in question:
            answer = "Exam timetable ke liye examination section check karein."

        elif "fee" in question:
            answer = "Fee related information ke liye accounts department se contact karein."

        elif "attendance" in question:
            answer = "Attendance information ke liye apne subject teacher se contact karein."

        elif "timetable" in question:
            answer = "Dashboard se Timetable section open karke class schedule dekh sakte hain."

        elif "course" in question:
            answer = "Courses section me available courses ki information mil jayegi."

        elif "notice" in question:
            answer = "Latest college notices ke liye Notices section open karein."

        elif "hello" in question or "hi" in question:
            answer = "Hello! Main AI College Assistant hoon. Aap college se related question pooch sakte hain."

        else:
            answer = "Sorry, mujhe is question ka answer nahi pata."

    return render_template(
        "chatbot.html",
        answer=answer,
        question=question
    )


# =========================
# TIMETABLE
# =========================

@app.route("/timetable")
def timetable():
    timetable_data = [
        {
            "day": "Monday",
            "time": "09:00 AM - 10:00 AM",
            "subject": "Python",
            "room": "Room 101"
        },
        {
            "day": "Tuesday",
            "time": "10:00 AM - 11:00 AM",
            "subject": "Data Structures",
            "room": "Room 102"
        },
        {
            "day": "Wednesday",
            "time": "11:00 AM - 12:00 PM",
            "subject": "Database Management",
            "room": "Room 103"
        },
        {
            "day": "Thursday",
            "time": "09:00 AM - 10:00 AM",
            "subject": "Web Development",
            "room": "Lab 1"
        },
        {
            "day": "Friday",
            "time": "10:00 AM - 11:00 AM",
            "subject": "Artificial Intelligence",
            "room": "Lab 2"
        }
    ]

    return render_template(
        "timetable.html",
        timetable=timetable_data
    )


# =========================
# SERVER START
# =========================
@app.route("/dashboard")
def dashboard():
    return render_template("dashboard.html")

# =========================
# COURSES ROUTE
# =========================

@app.route("/courses")
def courses():

    courses = [
        {
            "name": "Python Programming",
            "description": "Python programming, variables, functions, loops, OOP and projects.",
            "duration": "3 Months"
        },
        {
            "name": "Data Structures & Algorithms",
            "description": "Arrays, Linked List, Stack, Queue, Trees, Graphs, Sorting and Searching.",
            "duration": "4 Months"
        },
        {
            "name": "Database Management",
            "description": "SQL, MySQL, database design, queries, joins and normalization.",
            "duration": "3 Months"
        },
        {
            "name": "Web Development",
            "description": "HTML, CSS, JavaScript, Flask and basic web application development.",
            "duration": "4 Months"
        },
        {
            "name": "Artificial Intelligence",
            "description": "AI fundamentals, machine learning, neural networks and AI applications.",
            "duration": "5 Months"
        },
        {
            "name": "Data Analytics",
            "description": "Excel, SQL, Python, Pandas, NumPy, Matplotlib and Power BI.",
            "duration": "4 Months"
        },
        {
            "name": "Machine Learning",
            "description": "Supervised learning, regression, classification, model training and evaluation.",
            "duration": "5 Months"
        }
    ]

    return render_template("courses.html", courses=courses)

# =========================
# NOTICES ROUTE
# =========================

@app.route("/notices")
def notices():

    notices = [
        {
            "title": "Semester Examination",
            "description": "Semester examination timetable will be announced soon."
        },
        {
            "title": "College Holiday",
            "description": "Students are advised to check the academic calendar for holidays."
        },
        {
            "title": "Assignment Submission",
            "description": "Submit your pending assignments before the given deadline."
        },
        {
            "title": "Attendance Notice",
            "description": "Students should maintain the required attendance percentage."
        }
    ]

    return render_template("notices.html", notices=notices)

if __name__ == "__main__":
    app.run(debug=True)




    answer = None
    question = ""

    timetable_data = [
        {
            "day": "Monday",
            "time": "09:00 AM - 10:00 AM",
            "subject": "Python",
            "room": "Room 101"
        },
        {
            "day": "Tuesday",
            "time": "10:00 AM - 11:00 AM",
            "subject": "Data Structures",
            "room": "Room 102"
        },
        {
            "day": "Wednesday",
            "time": "11:00 AM - 12:00 PM",
            "subject": "Database Management",
            "room": "Room 103"
        },
        {
            "day": "Thursday",
            "time": "09:00 AM - 10:00 AM",
            "subject": "Web Development",
            "room": "Lab 1"
        },
        {
            "day": "Friday",
            "time": "10:00 AM - 11:00 AM",
            "subject": "Artificial Intelligence",
            "room": "Lab 2"
        }
    ]

    if request.method == "POST":

        question = request.form.get("question", "").strip().lower()

        if "timetable" in question or "schedule" in question:
            answer = "College Timetable:\n"

            for item in timetable_data:
                answer += (
                    f"{item['day']} - "
                    f"{item['time']} - "
                    f"{item['subject']} - "
                    f"{item['room']}\n"
                )

        elif "admission" in question:
            answer = "Admission ke liye college admission office se contact karein."

        elif "exam" in question:
            answer = "Exam timetable ke liye examination section check karein."

        elif "fee" in question:
            answer = "Fee related information ke liye accounts department se contact karein."

        elif "attendance" in question:
            answer = "Attendance information ke liye apne subject teacher se contact karein."

        elif "course" in question:
            answer = "Courses section me available courses ki information mil jayegi."

        elif "notice" in question:
            answer = "Latest college notices ke liye Notices section open karein."

        elif "hello" in question or "hi" in question:
            answer = "Hello! Main AI College Assistant hoon. Aap college se related question pooch sakte hain."

        else:
            answer = "Sorry, mujhe is question ka answer nahi pata."
