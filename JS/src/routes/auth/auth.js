const express = require("express");
var bcrypt = require('bcrypt');
const router = express();
const jwt = require('jsonwebtoken');
var con = require('../../config/db.js');
const bodyparser = require("body-parser");
const jsonparser = bodyparser.json();
require('dotenv').config();
var email_use = null;
var token = null;

router.post("/register", jsonparser,(reqe, rese, next) => {
    
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

// login and create a token
router.post("/login", jsonparser,(reqe, rese, next) => {
    // rese.type("application/json");
    console.log(reqe.body);
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

module.exports = router;