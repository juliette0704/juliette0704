const express = require("express");
const app = express();
const port = 3000;
var mysql = require('mysql2');

// const mysql = require('mysql');
    
// let db = mysql.createConnection({
//     host: "juliettee",
//     user: "juliettee",
//     password: "07042003",
//     database: "ju",
// });

// db.connect(function(err) {
//     console.log("Connecté à la base de données MySQL!");
//     // db.query("USE ju", function (err, res) {
//     // console.log("Base de données utilisé !");
// });

var con = mysql.createConnection({
    host: process.env.MYSQL_HOST,
    user: process.env.MYSQL_USER,
    password: process.env.MYSQL_ROOT_PASSWORD,
    database: "ju",
});

con.connect(function(err) {
//   con.query("SELECT * FROM thomas", (err, result) => {
//     console.l"RESULT: og('result', result);
//   });
});

app.get('/', (req, res) => {
    res.send('hello world')
})

app.get("/name/:name", (req, res) => {
    con.query("SELECT * FROM thomas", (err, res) => {
        ('result'+ res);
    });
    // res.send(`Hello, ${req.params['name']}`) ;


    // db.connect(function(err) {
    //     if (err) throw err;
    //     console.log("Connected!");
    // });

    // db.connect(function(err) {
        // console.log("Connecté à la base de données MySQL!");
        // db.query("USE ju", function(err, result) {
        //     console.log("Base de données utilisé !");
        // });
    // });
    

    // db.connect(function(err) {
        // db.query("SELECT * FROM thomas", (result) {
        //     console.log(result);
        // });

    // });


});

app.listen(port, () => {
    console.log(`Example app listening at http://localhost:${port}`);
});