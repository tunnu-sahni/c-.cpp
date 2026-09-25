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

    cursor.execute("""
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            email TEXT UNIQUE NOT NULL,
            password TEXT NOT NULL,
            role TEXT DEFAULT 'student'
        )
    """)

    cursor.execute("""
        CREATE TABLE IF NOT EXISTS notices (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            title TEXT NOT NULL,
            content TEXT NOT NULL
        )
    """)

    cursor.execute("""
        CREATE TABLE IF NOT EXISTS courses (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            duration TEXT NOT NULL,
            description TEXT
        )
    """)

    cursor.execute("""
        CREATE TABLE IF NOT EXISTS faculty (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            subject TEXT NOT NULL,
            email TEXT
        )
    """)

    cursor.execute("""
        CREATE TABLE IF NOT EXISTS timetable (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            day TEXT NOT NULL,
            subject TEXT NOT NULL,
            time TEXT NOT NULL
        )
    """)

    # Admin account
    admin = cursor.execute(
        "SELECT * FROM users WHERE email = ?",
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
            """
            INSERT INTO notices (title, content)
            VALUES (?, ?)
            """,
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


import sqlite3

DB_NAME = "college.db"


def get_connection():
    conn = sqlite3.connect(DB_NAME)
    conn.row_factory = sqlite3.Row
    return conn


def init_db():
    conn = get_connection()

    conn.execute("""
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            email TEXT UNIQUE NOT NULL,
            password TEXT NOT NULL
        )
    """)

    conn.commit()
    conn.close()