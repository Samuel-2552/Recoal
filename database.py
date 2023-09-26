import sqlite3

conn = sqlite3.connect('student.db')

cursor = conn.cursor()

create_table = ''' 
CREATE TABLE IF NOT EXISTS STUDENTS (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    roll_no INTEGER NOT NULL,
    dept TEXT
)
'''

cursor.execute(create_table)

conn.commit()

conn.close()

