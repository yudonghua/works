<?php include('global.php'); ?>
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<link rel="stylesheet" href="//cdn.bootcss.com/bootstrap/3.3.5/css/bootstrap.min.css">
		<link rel="stylesheet" href="main.css">
	</head>
	<body class="mainPage">
		<h1><?php echo $site_title;?>
			<small><?php echo $site_subtitle;?></small>
		</h1>
		<div class="pull-right">
			<a href="/">Index</a> |
		<?php if(islogin()) { ?>
			<a href="/new.php">New topic</a> |
			<a href="/login.php?logout=1">Logout [<?php echo $_SESSION['username'];?>]</a>
		<?php } else { ?>
			<a href="/login.php">Login</a>
		<?php } ?>
		</div>
		<hr>
	</body>
</html>