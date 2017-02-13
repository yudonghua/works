<?php
include('common.php');
if(islogin() == false) {
	header('Location: login.php');
}
$title = $content = $message = '';
if($_SERVER['REQUEST_METHOD'] === 'POST') {
	// var_dump($_POST);
	$title = isset($_POST['title']) ? $_POST['title'] : '';
	$content = isset($_POST['content']) ? $_POST['content'] : '';
	$tid = createTopic($title, $content);
	if($tid === false) {
		$message = 'Something got wrong! Please try again, or contact with administrator.';
	}
	else {
		header('Location: /topic.php?tid='.$tid);
	}
}
?>
<p><?php echo $message;?></p>
<form action="new.php" method="post">
<p><input class="form-control" name="title" type="text" placeholder="Title" value="<?php echo $title;?>"></p>
<p><textarea class="form-control" name="content" rows="20" placeholder="Content"><?php echo $content;?></textarea></p>
<p align="center">
	<button class="btn btn-success" type="submit">Submit</button>
	<a class="btn btn-default">Cancel</a>
</p>
</form>