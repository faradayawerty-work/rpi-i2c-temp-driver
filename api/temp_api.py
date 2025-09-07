from flask import Flask, jsonify

app = Flask(__name__)

@app.route("/temperature")
def get_temperature():
    with open("../user_space_service/temperature.log") as f:
        lines = f.readlines()
        if lines:
            last_temp = lines[-1].strip()
        else:
            last_temp = "No data"
    return jsonify({"temperature": last_temp})

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)
