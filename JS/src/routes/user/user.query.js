const express = require("express");
var bcrypt = require('bcrypt');
const router = express();
const jwt = require('jsonwebtoken');
var con = require('../../config/db.js');
const bodyparser = require("body-parser");
const jsonparser = bodyparser.json();
require('dotenv').config();
var email_use = null;
// var token = null;
var token = require('../../index');


router.get("/user/:id",jsonparser, (reqe, rese, next) => {
    jwt.verify(token,process.env.TOKENSECRET, (err, verifiedJwt) => {
        var middleware = reqe.params.id;
        console.log(middleware);
        console.log(process.env.TOKENSECRET);
        con.query('select * from user where id = ?', [middleware], function(error, results, fields) {
            rese.send(results);
        });
    });
});

// show user information
router.get("/user/:email", jsonparser,(reqe, rese, next) => {
    jwt.verify(token,process.env.TOKENSECRET, (err, verifiedJwt) => {
        var middleware = reqe.params.id;
        con.query('select * from user where email = ?', [middleware], function(error2, results2, fields2) {
            rese.send(results2);
        });
    });
});

// update user information
router.put("/users/:id", jsonparser,(reqe, rese, next) => {
    jwt.verify(token,process.env.TOKENSECRET, (err, verifiedJwt) => {
        var middleware = reqe.params.id;
        var email = reqe.body.email;
        var namee = reqe.body.name;
        var password = reqe.body.password;
        var firstname = reqe.body.firstname;
        
        bcrypt.hash(password, 5, function( err, bcryptedPassword) {
            var user={
                "email":email,
                "password":bcryptedPassword,
                "name":namee,
                "firstname":firstname,
                "created_at":new Date()
            }
            con.query('update user set name = ?, password = ?, email = ?, firstname = ?  where id = ?', [user.name, user.password, user.email, user.firstname, middleware], function(error, results, fields) {
                con.query('select * from user where id = ?', [middleware], function(error2, results2, fields2) {
                    rese.send(results2);
                });
            });
        });
    });
});

module.exports = router;