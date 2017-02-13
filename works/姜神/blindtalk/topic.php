<?php
include('common.php');
if(islogin() == false) {
	header('Location: login.php');
}
if(!isset($_GET['tid'])) {
	echo 'No such article!';
	return;
}
if(($topic = getTopicInfoByTid($_GET['tid'])) === false) {
	echo 'No such article!';
	return;
}
// print_r($topic);
?>
<h2><?php echo $topic['title'];?></h2>
<div class="pull-left"><?php echo $topic['username'];?></div>
<div align="right">
	<a class="btn btn-danger btn-xs" href="reply.php?tid=<?php echo $topic['tid'];?>">Reply</a>
</div>
<?php $index=0;
foreach($topic['comments'] as $comment) { ?>
<div class="comment-box" id="comment-<?php echo $comment['cid'];?>">
	<div class="info">
		<div class="floor">#<?php echo ++$index;?></div>
		<div class="username">
			<span class="glyphicon glyphicon-user"></span>
			<span><?php echo $comment['username'];?></span>
		</div>
		<div class="time">
			<span class="glyphicon glyphicon-time"></span>
			<span><?php echo $comment['submitTime'];?></span>
		</div>
		<div class="time">
			<span class="glyphicon glyphicon-pencil"></span>
			<span><?php echo $comment['modifyTime'];?></span>
		</div>
	</div>
	<pre class="content"><?php echo $comment['content'];?></pre>
</div>
<?php }?>