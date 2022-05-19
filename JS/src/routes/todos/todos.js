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

router.post("/todos",jsonparser, (reqe, rese, next) => {
    const autheader = reqe.headers['authorization']
    const token = autheader && autheader.split(' ')[1]
    if (token == null) return rese.send({"msg": "No token, authorization denied"});
    jwt.verify(token,process.env.TOKENSECRET, (err, verifiedJwt) => {
        if (err) return rese.send({" msg ": " Token is not valid "})
        title = reqe.body.title
        description = reqe.body.description
        statuse = reqe.body.status
        user_id = reqe.body.user_id
        due_time = new Date(reqe.body.due_time);
        created_at = new Date();
        var user={
            "title":title,
            "description":description,
            "due_time":due_time,
            "status":statuse,
            "user_id":user_id,
            "created_at":new Date()
        }
        con.query('INSERT INTO todo SET ?',user);
        rese.status(201).json({
            "tite":title,
            "description":description,
            "due_time":due_time,
            "status":statuse,
            "user_id":user_id,
            "created_at":new Date()
        });
    });
});

// modify a todo
router.put("/todos/:id",jsonparser, (reqe, rese, next) => {
    var middleware = reqe.params.id;
    const autheader = reqe.headers['authorization']
    const token = autheader && autheader.split(' ')[1]
    if (token == null) return rese.send({"msg": "No token, authorization denied"});
    jwt.verify(token,process.env.TOKENSECRET, (err, verifiedJwt) => {
        if (err) return rese.send({" msg ": " Token is not valid "})
        title = reqe.body.title
        description = reqe.body.description
        statuse = reqe.body.status
        user_id = reqe.body.user_id
        due_time = new Date(reqe.body.due_time);
        created_at = 1
        
        var user={
            "title":title,
            "description":description,
            "due_time":due_time,
            "user_id":user_id,
            "status":statuse,
        }

        con.query('SELECT * FROM todo WHERE id = ?', [middleware], function(error2, results2, fields) {
            if (error2) rese.send({"msg":"Internal server error"});
            else if (results2[0] == undefined) return rese.send({"msg": "Not Found"});
            else {
                con.query('update todo set title = ?, description = ?, status = ?, user_id = ?, due_time, ? where id = ?', [user.title, user.description, user.status, user.user_id, user.due_time, middleware], function(error, results, fields) {
                    // if (error) return rese.send({"msg":"Internal server error"});
                    // else {
                        con.query('select * from todo where id = ?', [middleware], function(error2, results2, fields2) {
                            if (error2) rese.send({"msg": "Internal server error"});
                            else {
                                rese.send(user);
                            };
                        });
                    // };
                });
                }
            });
        });
});

module.exports = router;
