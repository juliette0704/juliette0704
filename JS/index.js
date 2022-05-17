const express = require("express");
const app = express();
var bcrypt = require('bcrypt');
const port = 3000;
var mysql = require('mysql');
const router = express.Router();
const dotenv = require('dotenv');
const bodyParser = require("body-parser");
const jwt = require('jsonwebtoken');
require('dotenv').config();
var email_use = null;
var token = null;

var con = mysql.createConnection({
    host: "localhost",
    user: "valeria",
    password: "secretpass",
    database: "db1",
});

con.connect(function(err) {
    
});

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

router.post("/register", (reqe, rese, next) => {
    firstname = reqe.body.firstname
    namee = reqe.body.name
    password = reqe.body.password
    email = reqe.body.email
    created_at = 5
    bcrypt.hash(password, 5, function( err, bcryptedPassword) {
        var user={
            "email":email,
            "password":bcryptedPassword,
            "name":namee,
            "firstname":firstname,
            "created_at":new Date()
        }
        con.query('INSERT INTO user SET ?',user);
    });
    rese.status(201).json({
        "firstname": firstname,
        "name": namee,
        "created_at": new Date,
        "password": password,
        "email": email,
    });
});

router.post("/login", (reqe, rese, next) => {
    console.log("hello");
    password = reqe.body.password
    email = reqe.body.email
    console.log(reqe.body.password);
    console.log(reqe.body.email);
    con.query('SELECT password FROM user WHERE email = ?', [email], function(error, results, fields) {
        var password_db = results[0];
        password_db = password_db['password'];
        bcrypt.compare(password, password_db, function(errBycrypt, resBycrypt) {
            if (resBycrypt) {
                email_use = email;
                token = jwt.sign({email}, "v54bg54gbffbne8GJOIjoihGUUFT65ufto8grejfezo8gerofj", { expiresIn: '1800s' });

                console.log(token);
            }
        });
    });
    rese.status(201).json({
        "password": password,
        "email": email,
    });
});

router.get("/user", (reqe, rese, next) => {
    jwt.verify(token,"v54bg54gbffbne8GJOIjoihGUUFT65ufto8grejfezo8gerofj", (err, verifiedJwt) => {
        con.query('select * from user', function(error, results, fields) {
            rese.send(results);
        });
    });
});

router.get("/user/todo", (reqe, rese, next) => {
    jwt.verify(token,"v54bg54gbffbne8GJOIjoihGUUFT65ufto8grejfezo8gerofj", (err, verifiedJwt) => {
        con.query('select id from user where email = ?', [email_use], function(error, results, fields) {
            var iduse = results[0];
            // iduse = iduse['id'];
            con.query('select * from todo where user_id = ?', [iduse], function(error2, results2, fields2) {
                rese.send(results2);
            });
        }); 
    });
});

router.get("/user/:id", (reqe, rese, next) => {
    jwt.verify(token,"v54bg54gbffbne8GJOIjoihGUUFT65ufto8grejfezo8gerofj", (err, verifiedJwt) => {
        var middleware = reqe.params.id;
        con.query('select * from user where id = ?', [middleware], function(error, results, fields) {
            con.query('select * from user where email = ?', [email_use], function(error2, results2, fields2) {
                rese.send(results2);
            });
        });
    });
});

router.get("/user/:email", (reqe, rese, next) => {
    jwt.verify(token,"v54bg54gbffbne8GJOIjoihGUUFT65ufto8grejfezo8gerofj", (err, verifiedJwt) => {
        var middleware = reqe.params.id;
        con.query('select * from user where email = ?', [middleware], function(error2, results2, fields2) {
        con.query('select * from user where id = ?', [iduse], function(error, results, fields) {
                rese.send(results2);
            });
        });
    });
});




// delete user
// router.delete("/user/:userID", (reqe, rese, next) => {
//     req.params;
//     jwt.verify(token,"v54bg54gbffbne8GJOIjoihGUUFT65ufto8grejfezo8gerofj", (err, verifiedJwt) => {
//         con.query('delete from user where id = ?', [req.params["userID"]], function(error, results, fields) {
//             rese.status(204).json;
//         }); 
//     });
// });

//delete a todo
router.delete('/users/:id/', (reqe, rese, next) => {

    rese.send("oui");
    // var middleware = req.params.id;
    // con.query('delete from user where id = ?', [middleware], function(error, results, fields) {
    //     rese.send({
    //         "msg" : "succesfully  deleted  record  number: " + middleware
    //     })
    // });

    // req.params;
    // jwt.verify(token,"v54bg54gbffbne8GJOIjoihGUUFT65ufto8grejfezo8gerofj", (err, verifiedJwt) => {
    //     con.query('delete from todo where id = ?', [req.params["todoID"]], function(error, results, fields) {
    //         rese.status(204).json;
    //     }); 
    // });
});

app.get("/", async(req, res) => {
    res.send("hello");
    // if (err) throw err;

    // con.query("SELECT * FROM user", (err, result) => {
    //     res.status(200); 
    //     res.send('name = ' + result[0].id + ' address = ' + result[0].title);
    //     console.log(result);
    // });
});

app.use("/", router)

app.listen(port, () => {
    console.log(`Example app listening at http://localhost:${port}`);
});