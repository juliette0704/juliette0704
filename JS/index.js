const express = require("express");
const app = express();
const port = 3000;
var mysql = require('mysql');

var con = mysql.createConnection({
    host: "localhost",
    user: "juliettee",
    password: "07042003",
    database: "ju",
});

con.connect(function(err) {
    
});

app.get("/name/:name", (req, res) => {
    
    con.query("SELECT * FROM thomas", (err, res) => {
        
        console.log('result = '+ res);
    });


});

app.listen(port, () => {
    console.log(`Example app listening at http://localhost:${port}`);
});