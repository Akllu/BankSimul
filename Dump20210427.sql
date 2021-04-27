-- MySQL dump 10.13  Distrib 8.0.23, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: testi
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
INSERT INTO `asiakas` VALUES (1,'234','Matti Mainio','aatie 1','040 2222222','-06000DE540'),(2,'213','Jaakko Kolmonen','beetie 1','040 2222221','-06000DE53B'),(3,'214','Pekka Puupaa','Ceetie 1','040 2222223','-06000E1B4D'),(4,NULL,NULL,NULL,NULL,NULL),(5,NULL,NULL,NULL,NULL,NULL),(6,NULL,NULL,NULL,NULL,NULL);
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
INSERT INTO `asiakas_tili` VALUES (1,1),(2,2),(3,3);
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
INSERT INTO `kortti` VALUES (1,'$2a$10$P1rHLmGXJ7KE19HC2YaHHeX./vmKjVPAU9sfvk4EeaWNkMxHZ.9XG','112233',1,'-06000DE540',0),(2,'$2a$10$kLH1cqvKkZo.qXs/u/U6L.Z256gS7dKr72/xcqe6Z1pWhmZwfVq5e','112244',2,'-06000DE53B',0),(3,'$2a$10$RZC5U3mf5gDNg9r5CXwbNu6mog.gJVzIaypV8jaBbHocvc..hzETi','112255',3,'-06000E1B4D',0);
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
) ENGINE=InnoDB AUTO_INCREMENT=200 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tapahtuma`
--

LOCK TABLES `tapahtuma` WRITE;
/*!40000 ALTER TABLE `tapahtuma` DISABLE KEYS */;
INSERT INTO `tapahtuma` VALUES (167,'otto',20,'2021-04-27 08:52:51',2,NULL),(168,'otto',40,'2021-04-27 08:53:01',2,NULL),(169,'otto',60,'2021-04-27 08:53:09',2,NULL),(170,'otto',100,'2021-04-27 08:53:14',2,NULL),(171,'otto',200,'2021-04-27 08:53:19',2,NULL),(172,'otto',500,'2021-04-27 08:53:23',2,NULL),(173,'otto',600,'2021-04-27 08:53:30',2,NULL),(174,'pano',1100.75,'2021-04-27 08:54:41',3,NULL),(175,'otto',1100.75,'2021-04-27 08:54:41',2,NULL),(176,'pano',419.25,'2021-04-27 08:55:09',3,NULL),(177,'otto',419.25,'2021-04-27 08:55:09',2,NULL),(178,'otto',60,'2021-04-27 08:55:33',2,NULL),(179,'otto',500,'2021-04-27 08:56:59',1,NULL),(180,'otto',200,'2021-04-27 08:57:03',1,NULL),(181,'otto',470,'2021-04-27 08:57:24',1,NULL),(182,'pano',4000,'2021-04-27 08:59:33',3,NULL),(183,'otto',4000,'2021-04-27 08:59:33',1,NULL),(184,'pano',520.33,'2021-04-27 08:59:52',3,NULL),(185,'otto',520.33,'2021-04-27 08:59:52',1,NULL),(186,'pano',75.21,'2021-04-27 09:00:11',2,NULL),(187,'otto',75.21,'2021-04-27 09:00:11',1,NULL),(188,'pano',80000,'2021-04-27 09:00:32',3,NULL),(189,'otto',80000,'2021-04-27 09:00:32',1,NULL),(190,'otto',120,'2021-04-27 09:01:44',3,NULL),(191,'pano',30.5,'2021-04-27 09:02:21',2,NULL),(192,'otto',30.5,'2021-04-27 09:02:21',3,NULL),(193,'pano',21,'2021-04-27 09:02:31',1,NULL),(194,'otto',21,'2021-04-27 09:02:31',3,NULL),(195,'pano',110,'2021-04-27 09:02:48',2,NULL),(196,'otto',110,'2021-04-27 09:02:48',3,NULL),(197,'otto',20,'2021-04-27 09:02:53',3,NULL),(198,'pano',45,'2021-04-27 09:03:09',1,NULL),(199,'otto',45,'2021-04-27 09:03:09',3,NULL);
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
INSERT INTO `tili` VALUES (1,'12344',904280.4600000001),(2,'12345',179155.71),(3,'12346',96726.83),(4,'22222',6551),(5,'22221',2700);
/*!40000 ALTER TABLE `tili` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-04-27 12:03:56
