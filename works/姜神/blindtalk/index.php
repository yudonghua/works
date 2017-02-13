<?php
include('common.php');
if(islogin() == false) {
	header('Location: login.php');
}
$topics = getTopics();
// var_dump($topics);

foreach ($topics as $topic) { ?>
<a class="topic-box" href="topic.php?tid=<?php echo $topic['tid'];?>">
	<div class="title"><?php echo $topic['title'];?></div>
	<div class="author"><?php echo $topic['username'];?></div>
</a>
<?php }?>