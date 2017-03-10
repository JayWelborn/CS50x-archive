-- MySQL dump 10.13  Distrib 5.5.50, for debian-linux-gnu (x86_64)
--
-- Host: 0.0.0.0    Database: pset7
-- ------------------------------------------------------
-- Server version	5.5.50-0ubuntu0.14.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `history`
--

DROP TABLE IF EXISTS `history`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `history` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT,
  `user_id` int(255) NOT NULL,
  `method` varchar(10) NOT NULL,
  `symbol` varchar(10) NOT NULL,
  `num_shares` int(32) NOT NULL,
  `price` decimal(32,2) NOT NULL,
  `datetime` varchar(100) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=26 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `history`
--

LOCK TABLES `history` WRITE;
/*!40000 ALTER TABLE `history` DISABLE KEYS */;
INSERT INTO `history` VALUES (7,11,'Bought','GOOG',5,754.00,'13 Nov 2016, 14:12:48'),(8,11,'Bought','AMZN',4,739.01,'13, Nov, 2016, 14:39:52'),(9,11,'Bought','GOOG',10,754.02,'13 Nov 2016, 14:44:13'),(11,11,'Bought','AAP',10,145.02,'13 Nov 2016, 14:45:27'),(12,11,'Sold','AAP',1,145.02,'13 Nov 2016, 14:45:33'),(13,11,'Bought','GOOG',2,754.02,'13 Nov 2016, 14:48:06'),(14,11,'Bought','GOOG',2,754.02,'13 Nov 2016, 14:49:31'),(15,11,'Sold','AAP',1,145.02,'13 Nov 2016, 14:49:41'),(16,11,'Bought','AMZN',10,739.01,'13 Nov 2016, 18:54:57'),(17,11,'Bought','KKD',20,21.00,'13 Nov 2016, 19:08:22'),(18,11,'Bought','KKD',5,21.00,'13 Nov 2016, 19:12:33'),(19,11,'Add Funds','----',0,1000.00,'14 Nov 2016, 18:54:00'),(20,11,'Add Funds','----',0,-20.00,'14 Nov 2016, 18:57:53'),(21,12,'Bought','AMZN',10,720.36,'14 Nov 2016, 19:10:13'),(22,13,'Add Funds','----',0,100000000000.00,'14 Nov 2016, 19:37:16'),(23,13,'Bought','GOOG',1000,740.00,'14 Nov 2016, 19:37:27'),(24,13,'Sold','GOOG',500,740.80,'14 Nov 2016, 19:38:01'),(25,13,'Bought','AAP',50,144.24,'14 Nov 2016, 19:38:10');
/*!40000 ALTER TABLE `history` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `portfolio`
--

DROP TABLE IF EXISTS `portfolio`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `portfolio` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `user_id` int(10) NOT NULL,
  `symbol` varchar(255) NOT NULL,
  `shares` int(32) unsigned NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `user_id` (`user_id`,`symbol`),
  UNIQUE KEY `id` (`id`),
  UNIQUE KEY `user_id_2` (`user_id`,`symbol`)
) ENGINE=InnoDB AUTO_INCREMENT=22 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `portfolio`
--

LOCK TABLES `portfolio` WRITE;
/*!40000 ALTER TABLE `portfolio` DISABLE KEYS */;
INSERT INTO `portfolio` VALUES (2,10,'GOOG',5),(3,1,'GOOG',2),(5,9,'YHOO',3),(8,9,'LOW',5),(10,9,'GOOG',9),(11,9,'AMZN',1),(15,11,'AAP',8),(16,11,'GOOG',4),(17,11,'AMZN',10),(18,11,'KKD',25),(19,12,'AMZN',10),(20,13,'GOOG',500),(21,13,'AAP',50);
/*!40000 ALTER TABLE `portfolio` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(255) NOT NULL,
  `hash` varchar(255) NOT NULL,
  `cash` decimal(65,2) unsigned NOT NULL DEFAULT '0.00',
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=14 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,'andi','$2y$10$c.e4DK7pVyLT.stmHxgAleWq4yViMmkwKz3x8XCo4b/u3r8g5OTnS',10000.00),(2,'caesar','$2y$10$0p2dlmu6HnhzEMf9UaUIfuaQP7tFVDMxgFcVs0irhGqhOxt6hJFaa',10000.00),(3,'eli','$2y$10$COO6EnTVrCPCEddZyWeEJeH9qPCwPkCS0jJpusNiru.XpRN6Jf7HW',10000.00),(4,'hdan','$2y$10$o9a4ZoHqVkVHSno6j.k34.wC.qzgeQTBHiwa3rpnLq7j2PlPJHo1G',10000.00),(5,'jason','$2y$10$ci2zwcWLJmSSqyhCnHKUF.AjoysFMvlIb1w4zfmCS7/WaOrmBnLNe',10000.00),(6,'john','$2y$10$dy.LVhWgoxIQHAgfCStWietGdJCPjnNrxKNRs5twGcMrQvAPPIxSy',10000.00),(7,'levatich','$2y$10$fBfk7L/QFiplffZdo6etM.096pt4Oyz2imLSp5s8HUAykdLXaz6MK',10000.00),(8,'rob','$2y$10$3pRWcBbGdAdzdDiVVybKSeFq6C50g80zyPRAxcsh2t5UnwAkG.I.2',10000.00),(9,'skroob','$2y$10$395b7wODm.o2N7W5UZSXXuXwrC0OtFB17w4VjPnCIn/nvv9e4XUQK',10102.51),(10,'zamyla','$2y$10$UOaRF0LGOaeHG4oaEkfO4O7vfI34B1W23WqHr9zCpXL68hfQsS3/e',10000.00),(11,'test','$2y$10$cSTLHSyb4k7Mr2O7/mev.uOTylw5lR3ex4doyrZ006ICuoEXkQcxe',9081.95),(12,'test2','$2y$10$YiMaPJxtBPdNRielNSLhkulv0nZuLoYzB3ZiWcWLZNVrRdPxoUa5G',9279.64),(13,'jaywelborn','$2y$10$cKQC.d6AIayPBH42IGuiquVm4dnloWn.eD8tSEIko4RPjwPcKU2kS',100000009856.56);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-11-14 19:50:15
