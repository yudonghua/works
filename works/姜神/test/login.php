<?php
@session_start();
if($_SERVER['REQUEST_METHOD'] === 'POST') {
	mysql_connect('localhost', 'root', 'root'); // mysql -uroot -proot
	mysql_select_db('testMysql'); // USE testMysql;
	$username = $_POST['username'];
	$password = $_POST['password'];
	$sqlUser = mysql_query('SELECT * FROM `user` WHERE `username`="'.$username.'";');
	if($password === mysql_fetch_assoc($sqlUser)['password']) {
		$_SESSION['login'] = true;
	}
	else {
		$_SESSION['login'] = false;
	}
}
var_dump($_SESSION);
// $_GET $_POST $_SERVER $_SESSION
if(isset($_SESSION['login']) && $_SESSION['login'] === true) {
	echo 'login successfully!';
}
else {
	echo 'not login';
}
?>
<form method="post" action="login.php">
<input type="text" name="username">
<input type="text" name="password">
<input type="submit" value="login">
</form>