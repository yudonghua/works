<?php
$conn_hostname = 'localhost';
$conn_username = 'root';
$conn_password = 'root';
$conn_database = 'btbbs';
@mysql_connect($conn_hostname, $conn_username, $conn_password)
or die('{"result": "Failed to connect database."}');
@mysql_select_db($conn_database)
or die('{"result": "Failed to connect mysql."}');
