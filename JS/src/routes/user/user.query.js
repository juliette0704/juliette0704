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


router.get("/users/:id",jsonparser, (reqe, rese, next) => {
    const autheader = reqe.headers['authorization']
    const token = autheader && autheader.split(' ')[1]
    if (token == null) return rese.send({"msg": "No token, authorization denied"});
    jwt.verify(token,process.env.TOKENSECRET, (err, verifiedJwt) => {
        if (err) return rese.send({" msg ": " Token is not valid "})
        var middleware = reqe.params.id;
        con.query('select * from user where id = ?', [middleware], function(error, results, fields) {
            if (error) return rese.send({"msg": "Internal server error"});
            else if (results[0] == undefined) {
                con.query('select * from user where email = ?', [middleware], function(error2, results2, fields2) {
                    if (error) rese.send({"msg":"Internal server error"});
                    else if (results2[0] == undefined) return rese.send({"msg": "Not fouooooooond"});
                    else rese.send(results2);
                });
            }
                else rese.send(results);
        });
    });
});

// update user information
router.put("/users/:id", jsonparser,(reqe, rese, next) => {
    const autheader = reqe.headers['authorization']
    const token = autheader && autheader.split(' ')[1]
    if (token == null) return rese.send({"msg": "No token, authorization denied"});
    jwt.verify(token,process.env.TOKENSECRET, (err, verifiedJwt) => {
        if (err) return rese.send({" msg ": " Token is not valid "})
        var middleware = reqe.params.id;
        var email = reqe.body.email;
        var namee = reqe.body.name;
        var password = reqe.body.password;
        var firstname = reqe.body.firstname;

        if (email == null || namee == null || password == null || firstname == null) rese.send({"msg": "Bad parameter"});
        else {
            bcrypt.hash(password, 5, function( err, bcryptedPassword) {
                var user={
                    "email":email,
                    "password":bcryptedPassword,
                    "name":namee,
                    "firstname":firstname,
                }
                con.query('SELECT * FROM user WHERE id = ?', [middleware], function(error, results, fields) {
                    if (error) return rese.send({"msg": "Internal server error"});
                    else if (results[0] == undefined) return rese.send({"msg": "Not found"});
                    else {
                        con.query('update user set name = ?, password = ?, email = ?, firstname = ?  where id = ?', [user.name, user.password, user.email, user.firstname, middleware], function(error, results, fields) {
                            if (error) return rese.send({"msg":"Internal server error"})
                            con.query('select * from user where id = ?', [middleware], function(error2, results2, fields2) {
                                if (results2[0] == undefined) return rese.send({"msg": "Not found"});
                                rese.send(results2);
                            });
                        });
                    };
                });
            });
        };
    });
});

module.exports = router;