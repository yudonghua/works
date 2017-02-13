<?php
include('common.php');
if(isset($_GET['logout']) && $_GET['logout']) {
	$_SESSION['login'] = false;
	header('Location: /');
}
$message = '';
if($_SERVER['REQUEST_METHOD'] === 'POST') {
	if(!isset($_POST['username']) || !isset($_POST['password'])) {
		$message = 'Please check your input!';
	}
	else if(!checkUsernameValid($_POST['username'])) {
		$message = 'The username you input is not valid.';
	}
	else if(!verifyPassword($_POST['username'], $_POST['password'])) {
		$message = 'Wrong password to the username!';
	}
	else {
		$_SESSION['username'] = $_POST['username'];
		$_SESSION['uid'] = getUserInfoByUsername($_POST['username'])['uid'];
		$_SESSION['login'] = true;
		header('Location: /');
	}
}
?>
<h2 align="center">Login</h2>
<form method="post" action="login.php">
<table class="centerBox">
	<tr>
		<td width="100px">username</td>
		<td>
			<input class="form-control input-sm" name="username" type="text" placeholder="please input username here">
		</td>
	</tr>
	<tr>
		<td width="100px">password</td>
		<td>
			<input class="form-control input-sm" name="password" type="password" placeholder="please input password here">
		</td>
	</tr>
	<tr>
		<td></td>
		<td><span class="text-danger"><?php echo $message;?></span></td>
	</tr>
	<tr>
		<td></td>
		<td><button class="btn btn-danger" type="submit">Sign In</button></td>
	</tr>
	<tr>
		<td></td>
		<td><a href="register.php">Do not have an account yet.</a></td>
	</tr>
</table>
</form>