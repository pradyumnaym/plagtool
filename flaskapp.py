from flask import *  
app = Flask(__name__)  
 
@app.route('/')  
def upload():  
    return render_template("index.html")  

@app.route('/makesubmission', methods = ["POST"])
def submit():
    #create a new submission folder here.
    print(request.files)
    return jsonify({}), 200
    
@app.route('/success', methods = ['GET'])  
def success():  
    return render_template("viewResults.html", name = request.args.get("subid"))  
  
if __name__ == '__main__':  
    app.run(debug = True, port = 1000)  