const express = require("express");
const app = express();
var bcrypt = require('bcrypt');
const port = 3000;
var mysql = require('mysql2');
const router = express();
const dotenv = require('dotenv');
const bodyParser = require("body-parser");
const jwt = require('jsonwebtoken');
var con = require('./config/db.js');
require('dotenv').config();
var email_use = null;
var token = null;
var password = null;

console.log(process.env.TOKENSECRET);
app.use(require('./routes/auth/auth'));
app.use(require('./routes/todos/todos'));
app.use(require('./routes/user/user.query'));
app.use(require('./routes/user/user'));
app.use(require('./routes/todos/todos.query'));

app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

app.get("/", async(req, res) => {
    res.send("hello");
});

app.use("/", router)

app.listen(port, () => {
    console.log(`Example app listening at http://localhost:${port}`);
});