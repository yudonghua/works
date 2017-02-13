<?php include('common.php');
$message = '';
if($_SERVER['REQUEST_METHOD'] === 'POST') {
	if(!isset($_POST['username']) || !isset($_POST['password'])) {
		$message = 'Please check your input!';
	}
	else if(!checkUsernameValid($_POST['username'])) {
		$message = 'The username you input is not valid.';
	}
	else if(getUserInfoByUsername($_POST['username'])) {
		$message = 'The username has already been taken up.';
	}
	else {
		createUser($_POST['username'], $_POST['password']);
		header('Location: login.php');
	}
}
?>
<h2 align="center">Register</h2>
<form method="post" action="register.php">
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
		<td><button class="btn btn-danger" type="submit">Sign Up</button></td>
	</tr>
	<tr>
		<td></td>
		<td><a href="login.php">Have an account already.</a></td>
	</tr>
</table>
</form>