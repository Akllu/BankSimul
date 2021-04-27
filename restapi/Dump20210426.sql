-- MySQL dump 10.13  Distrib 8.0.23, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: mydb
-- ------------------------------------------------------
-- Server version	8.0.18

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `asiakas`
--

DROP TABLE IF EXISTS `asiakas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `asiakas` (
  `id_Asiakas` int(11) NOT NULL AUTO_INCREMENT,
  `tunnus` varchar(45) DEFAULT NULL,
  `nimi` varchar(45) DEFAULT NULL,
  `osoite` varchar(45) DEFAULT NULL,
  `puhelinnumero` varchar(45) DEFAULT NULL,
  `kortin_tunnus` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`id_Asiakas`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `asiakas`
--

LOCK TABLES `asiakas` WRITE;
/*!40000 ALTER TABLE `asiakas` DISABLE KEYS */;
INSERT INTO `asiakas` VALUES (1,'234','Matti Mainio','aatie 1','040 2222222','-06000DE540'),(2,'213','Jaakko Kolmonen','beetie 1','040 2222221','-06000DE53B'),(3,'214','Nii Juu','Ceetie 1','040 2222223','-06000E1B4D'),(4,NULL,NULL,NULL,NULL,NULL),(5,NULL,NULL,NULL,NULL,NULL),(6,NULL,NULL,NULL,NULL,NULL);
/*!40000 ALTER TABLE `asiakas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `asiakas_tili`
--

DROP TABLE IF EXISTS `asiakas_tili`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `asiakas_tili` (
  `id_Asiakas` int(11) NOT NULL,
  `id_Tili` int(11) DEFAULT NULL,
  KEY `fk_Asiakas_tili_Tili1_idx` (`id_Tili`),
  KEY `fk_Asiakas_tili_Asiakas` (`id_Asiakas`),
  CONSTRAINT `fk_Asiakas_tili_Asiakas` FOREIGN KEY (`id_Asiakas`) REFERENCES `asiakas` (`id_Asiakas`),
  CONSTRAINT `fk_Asiakas_tili_Tili1` FOREIGN KEY (`id_Tili`) REFERENCES `tili` (`id_Tili`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `asiakas_tili`
--

LOCK TABLES `asiakas_tili` WRITE;
/*!40000 ALTER TABLE `asiakas_tili` DISABLE KEYS */;
INSERT INTO `asiakas_tili` VALUES (3,4),(1,2),(2,3);
/*!40000 ALTER TABLE `asiakas_tili` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `kortti`
--

DROP TABLE IF EXISTS `kortti`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `kortti` (
  `id_kortti` int(11) NOT NULL AUTO_INCREMENT,
  `Pin_koodi` varchar(255) DEFAULT NULL,
  `Kortinnumero` varchar(45) DEFAULT NULL,
  `id_Tili` int(11) NOT NULL,
  `Tunnus_kortti` varchar(45) DEFAULT NULL,
  `lukittu` tinyint(1) DEFAULT NULL,
  PRIMARY KEY (`id_kortti`),
  KEY `fk_kortti_Tili1_idx` (`id_Tili`),
  CONSTRAINT `fk_kortti_Tili1` FOREIGN KEY (`id_Tili`) REFERENCES `tili` (`id_Tili`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `kortti`
--

LOCK TABLES `kortti` WRITE;
/*!40000 ALTER TABLE `kortti` DISABLE KEYS */;
INSERT INTO `kortti` VALUES (1,'$2a$10$P1rHLmGXJ7KE19HC2YaHHeX./vmKjVPAU9sfvk4EeaWNkMxHZ.9XG','112233',2,'-06000DE540',0),(2,'$2a$10$kLH1cqvKkZo.qXs/u/U6L.Z256gS7dKr72/xcqe6Z1pWhmZwfVq5e','112244',3,'-06000DE53B',0),(3,'$2a$10$RZC5U3mf5gDNg9r5CXwbNu6mog.gJVzIaypV8jaBbHocvc..hzETi','112255',4,'-06000E1B4D',1);
/*!40000 ALTER TABLE `kortti` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tapahtuma`
--

DROP TABLE IF EXISTS `tapahtuma`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tapahtuma` (
  `id_tapahtuma` int(11) NOT NULL AUTO_INCREMENT,
  `Tapahtuma_tyyppi` varchar(45) DEFAULT NULL,
  `Rahan_maara` double DEFAULT NULL,
  `Paivays` timestamp NULL DEFAULT NULL,
  `id_Tili` int(11) NOT NULL,
  `kortintunnus` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`id_tapahtuma`),
  KEY `fk_tapahtuma_Tili1_idx` (`id_Tili`),
  CONSTRAINT `fk_tapahtuma_Tili1` FOREIGN KEY (`id_Tili`) REFERENCES `tili` (`id_Tili`)
) ENGINE=InnoDB AUTO_INCREMENT=159 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tapahtuma`
--

LOCK TABLES `tapahtuma` WRITE;
/*!40000 ALTER TABLE `tapahtuma` DISABLE KEYS */;
INSERT INTO `tapahtuma` VALUES (1,'otto',140,'2001-04-20 18:00:00',3,'-06000DE53B'),(2,'pano',200,'2003-04-20 18:00:00',3,'-06000DE53B'),(3,'pano',200,'2021-04-11 20:12:37',3,'-06000DE53B'),(4,'pano',200,'2021-03-31 21:00:00',3,'-06000DE53B'),(5,'otto',-230,'2021-04-11 20:16:02',3,'-06000DE53B'),(6,'pano',230,'2021-04-11 20:17:10',3,'-06000DE53B'),(7,'pano',2301,'2021-04-11 20:17:13',3,'-06000DE53B'),(8,'otto',-14,'2021-04-11 20:17:18',3,'-06000DE53B'),(9,'pano',40,'2021-04-11 20:17:31',3,'-06000DE53B'),(10,'pano',401,'2021-04-11 20:17:42',4,'-06000E1B4D'),(11,'pano',302,'2021-04-11 20:17:47',4,'-06000E1B4D'),(12,'otto',-453,'2021-04-11 20:17:53',4,'-06000E1B4D'),(13,'otto',-45,'2021-04-11 20:17:57',4,'-06000E1B4D'),(14,'otto',-343,'2021-04-11 20:18:32',2,'-06000DE540'),(15,'pano',2000,'2021-04-11 20:18:36',2,'-06000DE540'),(16,'pano',200,'2021-04-11 20:18:40',2,'-06000DE540'),(17,'pano',150,'2021-04-11 20:18:44',2,'-06000DE540'),(18,'pano',453,'2021-04-11 20:18:49',2,'-06000DE540'),(19,'pano',452,'2021-04-12 06:16:16',4,'-06000E1B4D'),(20,'otto',-452,'2021-04-12 06:16:29',4,'-06000E1B4D'),(21,'pano',200,'2021-04-12 06:31:26',3,'-06000DE53B'),(22,'pano',200,'2021-04-12 06:35:23',3,'-06000DE53B'),(23,'pano',200,'2021-04-12 06:38:31',2,'-06000DE540'),(24,'pano',200,'2021-04-12 06:39:12',2,'-06000DE540'),(25,'pano',200,'2021-04-12 06:40:42',3,'-06000DE53B'),(26,'pano',200,'2021-04-12 06:41:13',3,'-06000DE53B'),(27,'pano',200,'2021-04-12 06:41:31',2,'-06000DE540'),(28,'pano',200,'2021-04-12 06:41:49',2,'-06000DE540'),(29,'pano',200,'2021-04-12 06:42:13',2,'-06000DE540'),(30,'pano',200,'2021-04-12 06:43:24',2,'-06000DE540'),(31,'pano',200,'2021-04-12 06:47:51',2,'-06000DE540'),(32,'pano',200,'2021-04-12 06:48:20',2,'-06000DE540'),(33,'pano',200,'2021-04-12 06:53:40',2,'-06000DE540'),(34,'pano',200,'2021-04-12 06:57:57',2,'-06000DE540'),(35,'pano',200,'2021-04-12 06:58:09',2,'-06000DE540'),(36,'pano',500,'2021-04-12 06:58:23',2,'-06000DE540'),(37,'pano',500,'2021-04-12 07:04:30',3,'-06000DE53B'),(38,'pano',500,'2021-04-12 07:09:53',3,'-06000DE53B'),(39,'pano',500,'2021-04-12 07:10:07',3,'-06000DE53B'),(40,'pano',200,'2021-04-12 07:14:45',5,NULL),(41,'pano',200,'2021-04-12 07:28:40',5,NULL),(42,'otto',200,'2021-04-12 07:28:40',4,'-06000E1B4D'),(43,'pano',500,'2021-04-12 07:28:56',3,'-06000DE53B'),(44,'otto',500,'2021-04-12 07:28:56',4,'-06000E1B4D'),(45,'pano',2000,'2021-04-12 07:29:42',2,'-06000DE540'),(46,'otto',2000,'2021-04-12 07:29:42',3,'-06000DE53B'),(47,'pano',2000,'2021-04-12 07:29:53',2,'-06000DE540'),(48,'otto',2000,'2021-04-12 07:29:53',3,'-06000DE53B'),(49,'pano',400,'2021-04-14 07:37:02',2,'-06000DE540'),(50,'otto',400,'2021-04-14 07:37:02',3,'-06000DE53B'),(51,'pano',10,'2021-04-14 07:39:54',2,'-06000DE540'),(52,'otto',10,'2021-04-14 07:39:54',3,'-06000DE53B'),(53,'pano',10,'2021-04-14 07:44:00',3,'-06000DE53B'),(54,'otto',10,'2021-04-14 07:44:00',2,'-06000DE540'),(55,'pano',123,'2021-04-14 09:02:37',2,'-06000DE540'),(56,'otto',123,'2021-04-14 09:02:37',3,'-06000DE53B'),(57,'pano',200,'2021-04-14 09:03:50',2,'-06000DE540'),(58,'otto',200,'2021-04-14 09:03:50',3,'-06000DE53B'),(59,'pano',122,'2021-04-14 09:14:14',2,'-06000DE540'),(60,'otto',122,'2021-04-14 09:14:14',3,'-06000DE53B'),(61,'pano',213,'2021-04-14 09:23:35',2,'-06000DE540'),(62,'otto',213,'2021-04-14 09:23:35',3,'-06000DE53B'),(63,'pano',200,'2021-04-14 09:43:45',3,'-06000DE53B'),(64,'pano',200,'2021-04-14 09:44:37',2,'-06000DE540'),(65,'pano',200000,'2021-04-14 09:44:42',2,'-06000DE540'),(66,'pano',200000000,'2021-04-14 09:44:48',2,'-06000DE540'),(67,'otto',-200000000,'2021-04-14 09:46:31',2,'-06000DE540'),(68,'otto',-2000,'2021-04-14 09:47:08',2,'-06000DE540'),(69,'otto',-2000,'2021-04-14 09:47:10',2,'-06000DE540'),(70,'otto',-2000,'2021-04-14 09:47:10',2,'-06000DE540'),(71,'otto',-2000,'2021-04-14 09:47:11',2,'-06000DE540'),(72,'otto',-2000,'2021-04-14 09:48:47',2,'-06000DE540'),(73,'otto',-2000,'2021-04-14 09:50:54',2,'-06000DE540'),(74,'otto',-452,'2021-04-14 09:52:56',2,'-06000DE540'),(75,'otto',-200,'2021-04-14 09:55:20',2,'-06000DE540'),(76,'otto',-200,'2021-04-14 09:58:40',2,'-06000DE540'),(77,'otto',-200,'2021-04-14 09:58:42',2,'-06000DE540'),(78,'otto',-200,'2021-04-14 10:01:56',2,'-06000DE540'),(79,'otto',-10000,'2021-04-14 10:02:19',2,'-06000DE540'),(80,'otto',-100,'2021-04-14 10:08:37',2,'-06000DE540'),(81,'pano',100,'2021-04-14 10:10:38',2,'-06000DE540'),(82,'otto',100,'2021-04-14 10:10:38',3,'-06000DE53B'),(83,'otto',-200,'2021-04-14 10:50:35',2,'-06000DE540'),(84,'otto',-200,'2021-04-14 10:51:45',2,'-06000DE540'),(85,'pano',200,'2021-04-14 10:52:06',2,'-06000DE540'),(86,'otto',200,'2021-04-14 10:52:06',3,'-06000DE53B'),(87,'otto',-300,'2021-04-14 10:56:49',3,'-06000DE53B'),(88,'pano',300,'2021-04-14 10:57:49',2,'-06000DE540'),(89,'otto',300,'2021-04-14 10:57:49',4,'-06000E1B4D'),(90,'pano',24,'2021-04-15 05:38:19',2,'-06000DE540'),(91,'otto',24,'2021-04-15 05:38:19',3,'-06000DE53B'),(92,'pano',140,'2021-04-15 07:11:21',2,'-06000DE540'),(93,'otto',140,'2021-04-15 07:11:21',3,'-06000DE53B'),(94,'otto',-140,'2021-04-15 07:11:25',2,'-06000DE540'),(95,'pano',-140,'2021-04-15 07:11:25',3,'-06000DE53B'),(96,'otto',-140,'2021-04-15 07:12:21',2,'-06000DE540'),(97,'pano',-140,'2021-04-15 07:12:21',3,'-06000DE53B'),(98,'otto',-140,'2021-04-15 07:12:22',2,'-06000DE540'),(99,'pano',-140,'2021-04-15 07:12:22',3,'-06000DE53B'),(100,'otto',-140,'2021-04-15 07:12:22',2,'-06000DE540'),(101,'pano',-140,'2021-04-15 07:12:23',3,'-06000DE53B'),(102,'otto',-140,'2021-04-15 07:12:23',2,'-06000DE540'),(103,'pano',-140,'2021-04-15 07:12:23',3,'-06000DE53B'),(104,'otto',-140,'2021-04-15 07:12:23',2,'-06000DE540'),(105,'pano',-140,'2021-04-15 07:12:23',3,'-06000DE53B'),(106,'otto',-140,'2021-04-15 07:12:23',2,'-06000DE540'),(107,'pano',-140,'2021-04-15 07:12:23',3,'-06000DE53B'),(108,'otto',-140,'2021-04-15 07:12:23',2,'-06000DE540'),(109,'pano',-140,'2021-04-15 07:12:23',3,'-06000DE53B'),(110,'otto',-140,'2021-04-15 07:12:23',2,'-06000DE540'),(111,'pano',-140,'2021-04-15 07:12:23',3,'-06000DE53B'),(112,'otto',-140,'2021-04-15 07:12:23',2,'-06000DE540'),(113,'pano',-140,'2021-04-15 07:12:23',3,'-06000DE53B'),(114,'otto',-140,'2021-04-15 07:12:23',2,'-06000DE540'),(115,'pano',-140,'2021-04-15 07:12:23',3,'-06000DE53B'),(116,'otto',-140,'2021-04-15 07:12:24',2,'-06000DE540'),(117,'pano',-140,'2021-04-15 07:12:24',3,'-06000DE53B'),(118,'otto',-140,'2021-04-15 07:12:24',2,'-06000DE540'),(119,'pano',-140,'2021-04-15 07:12:24',3,'-06000DE53B'),(120,'otto',-140,'2021-04-15 07:12:24',2,'-06000DE540'),(121,'pano',-140,'2021-04-15 07:12:24',3,'-06000DE53B'),(122,'otto',-140,'2021-04-15 07:12:25',2,'-06000DE540'),(123,'pano',-140,'2021-04-15 07:12:25',3,'-06000DE53B'),(124,'otto',-140,'2021-04-15 07:12:25',2,'-06000DE540'),(125,'pano',-140,'2021-04-15 07:12:25',3,'-06000DE53B'),(126,'otto',-140,'2021-04-15 07:12:25',2,'-06000DE540'),(127,'pano',-140,'2021-04-15 07:12:25',3,'-06000DE53B'),(128,'otto',-140,'2021-04-15 07:12:25',2,'-06000DE540'),(129,'pano',-140,'2021-04-15 07:12:25',3,'-06000DE53B'),(130,'otto',-1234,'2021-04-22 08:49:42',2,NULL),(131,'pano',1000,'2021-04-22 08:51:56',2,NULL),(132,'otto',-1234,'2021-04-23 08:20:58',2,NULL),(133,'otto',-222,'2021-04-23 08:26:06',2,NULL),(134,'otto',-1234,'2021-04-25 13:03:54',2,NULL),(135,'otto',123,'2021-04-25 13:14:49',3,NULL),(142,'pano',30,'2021-04-25 14:25:44',3,NULL),(143,'pano',30,'2021-04-25 14:31:44',4,NULL),(144,'pano',33,'2021-04-25 14:32:11',2,NULL),(145,'pano',30,'2021-04-25 14:33:17',4,NULL),(146,'pano',30,'2021-04-25 14:34:43',2,NULL),(147,'pano',30,'2021-04-25 14:47:00',2,NULL),(148,'pano',30,'2021-04-26 09:03:48',4,NULL),(149,'pano',30,'2021-04-26 09:53:29',2,NULL),(150,'pano',30,'2021-04-26 09:53:47',2,NULL),(151,'pano',30,'2021-04-26 09:55:16',2,NULL),(152,'otto',30,'2021-04-26 09:55:16',3,NULL),(153,'pano',33,'2021-04-26 09:56:11',2,NULL),(154,'otto',33,'2021-04-26 09:56:11',3,NULL),(155,'pano',33,'2021-04-26 09:57:49',2,NULL),(156,'otto',33,'2021-04-26 09:57:49',3,NULL),(157,'pano',33,'2021-04-26 09:58:21',3,NULL),(158,'otto',33,'2021-04-26 09:58:21',2,NULL);
/*!40000 ALTER TABLE `tapahtuma` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tili`
--

DROP TABLE IF EXISTS `tili`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tili` (
  `id_Tili` int(11) NOT NULL AUTO_INCREMENT,
  `Tilinumero` varchar(45) DEFAULT NULL,
  `Tilin_saldo` double DEFAULT NULL,
  PRIMARY KEY (`id_Tili`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tili`
--

LOCK TABLES `tili` WRITE;
/*!40000 ALTER TABLE `tili` DISABLE KEYS */;
INSERT INTO `tili` VALUES (1,NULL,NULL),(2,'12345',182939),(3,'12346',94),(4,'22222',6551),(5,'22221',2700),(6,'22223',44300);
/*!40000 ALTER TABLE `tili` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'mydb'
--
/*!50003 DROP PROCEDURE IF EXISTS `nosto` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `nosto`(in id int, in summa double)
begin
start transaction;
update tili set Tilin_saldo=Tilin_saldo+summa where id_Tili=id and Tilin_saldo+summa>0;
set @test=row_count();
if(@test>0) then
	commit;
	if (summa>0) then 
	insert into tapahtuma(Tapahtuma_tyyppi, Rahan_maara, paivays, id_Tili) values('pano', -summa, now(), id);
	else
insert into tapahtuma(Tapahtuma_tyyppi, Rahan_maara, paivays, id_Tili) values('otto', -summa, now(), id);
end if;
else
Rollback;
end if;
end ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `siirto` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `siirto`(in id varchar(255), in id2 int, in summa double)
begin
start transaction;
update tili set Tilin_saldo=Tilin_saldo+summa where Tilinumero=id and Tilin_saldo+summa>0;
update tili set Tilin_saldo=Tilin_saldo-summa where id_Tili=id2 and Tilin_saldo-summa>0;
set @testi=row_count();
If(@testi>0) then
commit;
/*if(id>0) then*/
insert into tapahtuma(Tapahtuma_tyyppi, Rahan_maara, paivays,id_Tili) values('pano', summa, now(),(select id_Tili from tili where Tilinumero=id));
/*else*/
insert into tapahtuma(Tapahtuma_tyyppi, Rahan_maara, paivays,id_Tili) values('otto', summa, now(), id2);
/*end if;*/
else
rollback;
end if;
end ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-04-26 16:33:32
