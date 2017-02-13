<?php
	var_dump($_GET);
?>
<html>
	<head>
		<title></title>
		<meta charset="utf-8">
	</head>
	<body>
		<form method="GET" action="get.php">
			<input type="text" name="text1">
			<input type="text" name="text2">
			<input type="submit" value="save">
		</form>
		<br>
		<p>text1: <?php echo $_GET['text1'];?></p>
		<p>text2: <?php echo $_GET['text2'];?></p>
	</body>
</html>