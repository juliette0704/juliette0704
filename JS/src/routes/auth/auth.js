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
            "created_at":new Date
        }
        con.query('SELECT email FROM user WHERE email = ?',[email], function(error2, results2, fields2) {
            console.log(results2);
            if (results2[0] != undefined) return rese.send({"msg": "Account already exists"});
            else {
                con.query('INSERT INTO user SET ?',user);
                token = jwt.sign({email}, process.env.TOKENSECRET, { expiresIn: '1800s' });
                rese.status(201).json({
                    "token": token,
                });
            }
        });
    });
});

// login and create a token
router.post("/login", jsonparser,(reqe, rese, next) => {
    password = reqe.body.password
    email = reqe.body.email
    con.query('SELECT password FROM user WHERE email = ?', [email], function(error, results, fields) {
        if (results[0] == undefined) rese.send({"msg": "Invalid Credentials"});
        else {
            var password_db = results[0];
            password_db = password_db['password'];
            bcrypt.compare(password, password_db, function(errBycrypt, resBycrypt) {
                if (resBycrypt) {
                    email_use = email;
                    token = jwt.sign({email}, process.env.TOKENSECRET, { expiresIn: '1800s' });
                    console.log({"token": token});
                    rese.status(201).json({
                        // "password": password,
                        // "email": email,
                        "token": token
                    });
                }
                else rese.send({"msg": "Invalid Credentials"});
            });
        }
    });
});

module.exports = router;