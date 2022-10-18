from flask import Flask,render_template,url_for,request,redirect,flash
from flask_mysqldb import MySQL
app = Flask(__name__)

app.secret_key ="fgdfg22asdkgsdfg4dfg"

app.config['MYSQL_HOST'] = 'localhost'
app.config['MYSQL_USER'] = 'root'
app.config['MYSQL_PASSWORD'] = ''
app.config['MYSQL_DB'] = 'todolist'
mysql = MySQL(app)

@app.route('/')
def home():
    cur = mysql.connection.cursor()
    results = cur.execute("SELECT * FROM task_list")

    if results > 0:
        task_details = cur.fetchall()
        return render_template('home.html',tasks=task_details)

    return render_template('home.html')

@app.route('/taskPage')
def taskPage():

    

    return render_template("add_task.html")

@app.route('/add_task',methods=["POST","GET"])
def add_task():
    t_id = request.form['task_id']
    t_name = request.form['task_name']
    print(t_id,t_name)
    cur = mysql.connection.cursor()
    result = cur.execute("SELECT * from task_list")
    flag = False
    # if result > 0:
    task_results = cur.fetchall()
    print(task_results,t_id)
    for idd,task in task_results:
        if idd == int(t_id):
            flag = True
            break
    if flag:
        # print("In if")
        flash("That task id aleady have been teaken chooose anather one.")
        cur.close()
        return redirect(url_for("home"))
    else:
        cur.execute("INSERT INTO task_list(id,taskname) VALUES(%s,%s)",(t_id,t_name))
        mysql.connection.commit()
        cur.close()

        return redirect("/")

@app.route('/delete/<int:idd>')
def delete_data(idd):

    cur = mysql.connection.cursor()
    cur.execute(f"DELETE FROM task_list WHERE id={idd}")
    cur.connection.commit()
    cur.close()
    flash(f"task having task id {idd} has been deleted")
    return redirect("/") 


@app.route("/edit_task_page/<int:idd>")
def edit_task_page(idd):
    return render_template("edit_task.html",idd=idd)

@app.route("/edit_task/<int:idd>",methods=["POST","GET"])
def edit_task(idd):
    if request.method == "POST":
        new_task_name = request.form['edit']
        # print(new_task_namecm)
        cur = mysql.connection.cursor()
        cur.execute("UPDATE  task_list SET taskname=%s WHERE id=%s",(new_task_name,idd))
        cur.connection.commit()
        flash("Your task is updated")
        return redirect("/")
    else:
        flash("Please edit your task by clicking on button")
        return redirect("/")









# @app.route('/edit/<int:idd>')
# def edit_data(idd):

#     cur = mysql.connection.cursor()
#     cur.execute("UPDATE TABLE task_list SET taskname=")