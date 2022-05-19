const express = require("express");
const app = express();
var bcrypt = require('bcrypt');
const port = 3000;
var mysql = require('mysql2');
const router = express();
const dotenv = require('dotenv');
const bodyParser = require("body-parser");
const jwt = require('jsonwebtoken');
const res = require("express/lib/response");
require('dotenv').config();

var con = mysql.createConnection({
    host: "localhost",
    user: "valeria",
    password: "secretpass",
    database: "db1",
});

con.connect(function(err) {
    if (err) {
        console.log({"msg": "Internal server error"});
    }
});

module.exports = con;
