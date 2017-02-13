<?php
@session_start();
require_once('connection.php');
$site_title = 'Blind Talk BBS';
$site_subtitle = 'Speak without thinking!';

function islogin() {
	return isset($_SESSION['login']) && $_SESSION['login'];
}
function checkUsernameValid($username) { // length between [4, 20]
	return preg_match('/^[a-zA-Z][a-zA-Z0-9_]{3,19}$/', $username);
}
function getUserInfoByUid($uid) {
	$sqlUser = @mysql_query('SELECT * FROM `user` WHERE `uid`="'.$uid.'";');
	return mysql_fetch_assoc($sqlUser);
}
function getUserInfoByUsername($username) {
	$sqlUser = @mysql_query('SELECT * FROM `user` WHERE `username`="'.$username.'";');
	return mysql_fetch_assoc($sqlUser);
}
function verifyPassword($username, $password) {
	return getUserInfoByUsername($username)['password'] === md5($password);
}
function createUser($username, $password) {
	@mysql_query('INSERT INTO `user` (`username`, `password`) VALUES ("'.$username.'", "'.md5($password).'");');
}
function modifyUser($username, $password) {
	@mysql_query('UPDATE `user` SET `password`="'.md5($password).'" WHERE `username`="'.$username.'";');
}
function getTopics() {
	$sqlTopic = @mysql_query('SELECT * FROM `topic`;');
	$topics = [];
	while(($topic = @mysql_fetch_assoc($sqlTopic)) !== false) {
		$topic['username'] = getUserInfoByUid($topic['uid'])['username'];
		array_push($topics, $topic);
	}
	return $topics;
}
function getTopicInfoByTid($tid) {
	$res = [];
	$sqlTopic = @mysql_query('SELECT * FROM `topic` WHERE `tid`="'.$tid.'";');
	if($sqlTopic === false) {
		return false;
	}
	$res = @mysql_fetch_assoc($sqlTopic);
	$res['username'] = getUserInfoByUid($res['uid'])['username'];
	$res['comments'] = getTopicCommentsByTid($tid);
	return $res;
}
function getTopicCommentsByTid($tid) {
	$sqlComment = @mysql_query('SELECT * FROM `comment` WHERE `tid` = "'.$tid.'";');
	$comments = [];
	while(($comment = @mysql_fetch_assoc($sqlComment)) !== false) {
		$comment['username'] = getUserInfoByUid($comment['uid'])['username'];
		$comment['content'] = urldecode($comment['content']);
		array_push($comments, $comment);
	}
	return $comments;
}
function createTopic($title, $content) {
	if(!islogin()) return false;
	$uid = $_SESSION['uid'];
	if(!@mysql_query('INSERT INTO `topic` (`title`, `uid`) VALUES ("'.$title.'", "'.$uid.'");')) return false;
	$tid = mysql_insert_id();
	if(!@mysql_query('INSERT INTO `comment` (`content`, `uid`, `tid`) VALUES ("'.$content.'", "'.$uid.'", "'.$tid.'");')) return false;
	return $tid;
}
function createComment($content, $tid) {
	if(!islogin()) return false;
	$uid = $_SESSION['uid'];
	if(!@mysql_query('INSERT INTO `comment` (`content`, `uid`, `tid`) VALUES ("'.$content.'", "'.$uid.'", "'.$tid.'");')) return false;
	return mysql_insert_id();
}