DROP DATABASE IF EXISTS `btbbs`;
CREATE DATABASE IF NOT EXISTS `btbbs` DEFAULT CHARACTER SET utf8 COLLATE utf8_bin ;
USE `btbbs`;

--
-- Table `btbbs`.`user`
--
DROP TABLE IF EXISTS `btbbs`.`user`;
CREATE TABLE IF NOT EXISTS `btbbs`.`user` (
	`uid` INT NOT NULL AUTO_INCREMENT,
	`username` VARCHAR(50) NOT NULL,
	`password` VARCHAR(50) NULL DEFAULT 0,
	PRIMARY KEY (`uid`),
	UNIQUE INDEX `uid_UNIQUE` (`uid` ASC)
)ENGINE = InnoDB;
INSERT INTO `btbbs`.`user` (`uid`, `username`, `password`) VALUES ('1', 'admin', MD5('admin'));
INSERT INTO `btbbs`.`user` (`uid`, `username`, `password`) VALUES ('2', 'tester', MD5('tester'));

--
-- Table `btbbs`.`topic`
--
DROP TABLE IF EXISTS `btbbs`.`topic`;
CREATE TABLE IF NOT EXISTS `btbbs`.`topic` (
	`tid` INT NOT NULL AUTO_INCREMENT,
	`title` TEXT NOT NULL,
	`uid` INT NOT NULL,
	PRIMARY KEY (`tid`),
	UNIQUE INDEX `tid_UNIQUE` (`tid` ASC)
)ENGINE = InnoDB;
INSERT INTO `btbbs`.`topic` (`tid`, `title`, `uid`) VALUES ('1', 'Welcome!', '1');

--
-- Table `btbbs`.`topic`
--
DROP TABLE IF EXISTS `btbbs`.`comment`;
CREATE TABLE IF NOT EXISTS `btbbs`.`comment` (
	`cid` INT NOT NULL AUTO_INCREMENT,
	`submitTime` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
	`modifyTime` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
	`content` TEXT NOT NULL,
	`uid` INT NOT NULL,
	`tid` INT NOT NULL,
	PRIMARY KEY (`cid`),
	UNIQUE INDEX `cid_UNIQUE` (`cid` ASC)
)ENGINE = InnoDB;
INSERT INTO `btbbs`.`comment` (`cid`, `content`, `uid`, `tid`) VALUES ('1', 'Welcome to the bbs. You can speak all you can!', '1', '1');
INSERT INTO `btbbs`.`comment` (`cid`, `content`, `uid`, `tid`) VALUES ('2', 'Really?', '2', '1');
INSERT INTO `btbbs`.`comment` (`cid`, `content`, `uid`, `tid`) VALUES ('3', 'Ha ha ha ha ha ...', '2', '1');
