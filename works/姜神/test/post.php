<?php
	var_dump($_POST);
?>
<html>
	<head>
		<title></title>
		<meta charset="utf-8">
	</head>
	<body>
		<form method="POST" action="post.php">
			<input type="text" name="text1">
			<input type="text" name="text2">
			<input type="submit" value="save">
		</form>
		<br>
		<p>text1: <?php echo $_POST['text1'];?></p>
		<p>text2: <?php echo $_POST['text2'];?></p>
	</body>
</html>