<?php
mysql_connect('localhost', 'root', 'root'); // mysql -uroot -proot
mysql_select_db('testMysql'); // USE testMysql;
if($_SERVER['REQUEST_METHOD'] === 'POST') {
	$username = $_POST['username'];
	$password = $_POST['password'];
	mysql_query('INSERT INTO `user` (`username`, `password`) VALUES ("'.$username.'", "'.$password.'");');
	// $uid = mysql_insert_id();
}
$sqlUser = mysql_query('SELECT * FROM `user`;');
// var_dump($sqlUser);
$list = [];
$data = [];
while(($data = mysql_fetch_assoc($sqlUser)) !== false) {
	array_push($list, $data);
}
// var_dump($data);
?>
<form method="post" action="register.php">
<input type="text" name="username">
<input type="text" name="password">
<input type="submit" value="register">
</form>
<pre>
<?php print_r($list);?>
</pre>
