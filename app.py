from flask import Flask, render_template, request, redirect
import sqlite3

app = Flask(__name__)

# Define a route for the home page
@app.route('/', methods=["GET", "POST"])
def home():
    a = "Shreya"
    if request.method == "POST":
        name = request.form.get("stud")
        reg = request.form.get("reg")
        dept = request.form.get("dept")

        conn = sqlite3.connect('student.db')

        cursor = conn.cursor()

        store = '''
        INSERT INTO STUDENTS (name, roll_no, dept) VALUES (?,?,?)
        '''

        cursor.execute(store, (name,reg,dept))

        conn.commit()

        conn.close()



        print(name)
        print(reg)
        print(dept)

        a="Details Stored"






    
    return render_template('home.html', value=a)

@app.route('/SIH')
def SIH():
    return render_template('index.html')

@app.route('/view')
def view():
    conn = sqlite3.connect('student.db')

    cursor = conn.cursor()

    cursor.execute("SELECT * from students")

    students = cursor.fetchall()
    conn.close()

    print(students)

    return render_template("table.html", students=students)


if __name__ == '__main__':
    app.run(debug=True)

