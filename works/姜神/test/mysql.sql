DROP DATABASE IF EXISTS `testMysql`;
CREATE DATABASE IF NOT EXISTS `testMysql` DEFAULT CHARACTER SET utf8 COLLATE utf8_bin ;
USE `testMysql`;

CREATE TABLE `user` (
	`uid` INT NOT NULL AUTO_INCREMENT,
	`username` VARCHAR(50) NOT NULL,
	`password` VARCHAR(50) NOT NULL DEFAULT 0,
	PRIMARY KEY (`uid`),
	UNIQUE INDEX `uid_UNIQUE` (`uid` ASC)
)ENGINE = InnoDB;