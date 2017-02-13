<?php
include('common.php');
if(islogin() == false) {
	header('Location: login.php');
}
$tid = isset($_GET['tid']) ? $_GET['tid'] : 0;
$topic = getTopicInfoByTid($tid);
$content = $message = '';
if($_SERVER['REQUEST_METHOD'] === 'POST') {
	// var_dump($_POST);
	$content = isset($_POST['content']) ? $_POST['content'] : '';
	$cid = createComment($content, $tid);
	if($cid === false) {
		$message = 'Something got wrong! Please try again, or contact with administrator.';
	}
	else {
		header('Location: /topic.php?tid='.$tid.'#comment-'.$cid);
	}
}
?>
<p><?php echo $message;?></p>
<form action="reply.php?tid=<?php echo $tid;?>" method="post">
<p>Reply to <em style="font-size: 20px;"><?php echo $topic['title']?></em></p>
<p><textarea class="form-control" name="content" rows="20" placeholder="Content"><?php echo $content;?></textarea></p>
<p align="center">
	<button class="btn btn-success" type="submit">Submit</button>
	<a class="btn btn-default">Cancel</a>
</p>
</form>