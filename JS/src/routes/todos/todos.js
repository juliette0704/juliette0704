const express = require("express");
var bcrypt = require('bcrypt');
const router = express();
const jwt = require('jsonwebtoken');
var con = require('../../config/db.js');
var token = require('../../index');
const bodyparser = require("body-parser");
const jsonparser = bodyparser.json();
require('dotenv').config();
var email_use = null;
// var token = null;

router.post("/todos",jsonparser, (reqe, rese, next) => {
    jwt.verify(token,process.env.TOKENSECRET, (err, verifiedJwt) => {
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
    jwt.verify(token,process.env.TOKENSECRET, (err, verifiedJwt) => {
        title = reqe.body.title
        description = reqe.body.description
        statuse = reqe.body.status
        user_id = reqe.body.user_id
        due_time = new Date(reqe.body.due_time);
        created_at = 0
        
        var user={
            "title":title,
            "description":description,
            "due_time":due_time,
            "status":statuse,
            "user_id":user_id,
            "created_at":new Date()
        }
        con.query('update todo set = ?, title = ?, description = ?, status = ?, user_id = ?, due_time = ? where id = ?', [user.title, user.description, user.status, user.user_id, user.due_time, middleware], function(error, results, fields) {
            con.query('select * from todo where id = ?', [middleware], function(error2, results2, fields2) {
                rese.send(results2);
            });
        });
    });
});

module.exports = router;
