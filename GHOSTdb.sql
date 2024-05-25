-- MariaDB dump 10.19  Distrib 10.4.32-MariaDB, for Win64 (AMD64)
--
-- Host: localhost    Database: fdb
-- ------------------------------------------------------
-- Server version	10.4.32-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `entity_accounts`
--

DROP TABLE IF EXISTS `entity_accounts`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `entity_accounts` (
  `UserID` int(10) NOT NULL AUTO_INCREMENT,
  `Username` varchar(50) DEFAULT NULL,
  `Password` varchar(255) DEFAULT NULL,
  `isAdmin` tinyint(1) DEFAULT NULL,
  PRIMARY KEY (`UserID`)
) ENGINE=InnoDB AUTO_INCREMENT=41 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `entity_accounts`
--

LOCK TABLES `entity_accounts` WRITE;
/*!40000 ALTER TABLE `entity_accounts` DISABLE KEYS */;
INSERT INTO `entity_accounts` VALUES (10,'Admin','$2y$10$L6W.e9PsY6S4pTn3DveZ9eKVLDJTWNeKgLXm5pyfAAB5olaDjSYVy',1),(11,'NewUser','$2y$10$4dsCk673k4M6IR7ippEjI.dL7wxYUH2ne4qHCI0e1stGckVn.WduK',NULL),(12,'Pokemaster','$2y$10$kwWhsXPkZAQE.xeOEhxyJ.fxiybIgQ3f/JmUBxrA5mLexCdsT4iK.',NULL),(13,'apple','$2y$10$f1T/eeomi73CBTlzWYwcVuwGk0RkViDMlcUIZ5Y7VELRoEtsxDZBG',NULL),(14,'pumpkin','$2y$10$yqHnP.GKoHjMcwpv2GZzfOB24wF2tVXGnZfhccv/qXj5gf8gvVr7K',NULL),(15,'test','$2y$10$A0mQ8ffP7fINR4T3eQbaxOESJJD13zhoL1S1qHS7cfc.chkiKKqqK',NULL),(17,'BBLDrizzy','$2y$10$Nt4MHGMpUllxC9Kh1ZadJ.uMbOQYZe4rpLn8Hb3V5PzGGXbQL/xkK',NULL),(18,'NoahScott','$2y$10$GpZ/24qUTojt1nWDC50yW.N28MgpJkGHELrcUIsDuPi4lqlmcvtlC',NULL),(19,'NewName','$2y$10$1o0Q4vaicLOtZthRH4ckseR/OOLr/kg1Z9FD0U5NWUTfUfc1amxYa',NULL),(20,'PineapplePizza','$2y$10$9lk95a1wRipwV/x.iym1DeX8ysjY0JFOhx/0GsEmg91wJhvvMXzuO',NULL),(21,'NewUser','$2y$10$TBvccSo603VzKrYfzw2ee.Caz6HVETTmxkFxUKU1anFti/NjfVKTO',NULL),(22,'NewUser','$2y$10$qxYkkyImlZUN1pF8kb9bqef.uvagqD59UVfAzKeLh072.7HZbl6FG',NULL),(23,'NewUser','$2y$10$ajNnHScAlDbiQfB9zyhTKeFljwBdHzgbWkhTEEqOiiaVhahO/D5gK',NULL),(24,'Toph','$2y$10$hh7g5SDIyebK9v.GmRG20O77ECCq61qXk2CWXLrjFnP9gRXnVuRk6',NULL),(25,'Toph','$2y$10$tdFZhhhugqtMUn1lu4i34eUCRCwzGjynjehLSU7l6Kzy38xYKbI4u',NULL),(26,'Aang','$2y$10$HAcYzpOIBGTv0i6Jgo1pl.0qgDg/87uldZKyxSNsrLX5lEeWWOYu2',NULL),(27,'Sokka','$2y$10$X8Y9ijCGLMWId9wtQcAPUu205iGnRIXVSaszt2z05QKjo971CHUdu',NULL),(28,'Huey','$2y$10$b5Egq0/AvbC/EbahdIvvPeaiVfpmlIffBtHP4NjIUWBr13Fva7u8e',NULL),(29,'ScoobyDoo','$2y$10$zR6mEa8wVD3or0on/6wZI.tK//bd1jldqmDUfJQ79GhzUSO5ULWO2',NULL),(30,'Cheese','$2y$10$olBQlmXdkVpS6Dx83Qq6iu5KcpXT1rOab3hojl9u9kXoscI.PurXe',NULL),(31,'Kendrick','$2y$10$D8F9dWcu8mwaPIpoohhex.amPLGTT4CvJd1mUtgLu/pQx7FyK63FC',NULL),(33,'PizzaHut','$2y$10$ghDXnfZvLjlxnMlVF9SmBOnXQ6Mru6Hm/dDRzYnk0/ETKSDSh/0La',0),(34,'PizzaHut','$2y$10$cLFZR.PjkMRpMTR7v0Y.w.8baxWtc2WVNNQ4MUAdPeTPz0qPBkhB.',0),(35,'PizzaHut','$2y$10$XYSBR6qquM6ly.8c7jvBIeKQWrXzpup6apwQODd2p42yewr59Mae.',0),(36,'PizzaHut','$2y$10$XOBhv8fxmhrQ56HvYQg4iOfcbmRBVazJo6M5ODVNOs6i6q7RH4wIe',0),(37,'PizzaHut','$2y$10$0LtxXTG7qYiTeT3efXOk9.npTZ/d2/PCNmZD5BAfQhCXM1CXrbp/K',0),(38,'PizzaHut','$2y$10$3wiZHBcjwg6dhiAjG6B0jutuUbFnyWzkRg77eh9CxlgOZzOhjeFyi',0),(39,'TurkeyMan','$2y$10$qYYczxuVUnngpBD0g7AYEOq.glc843sUDNdbao1Kc15TCiLsbsX22',0),(40,'ThisOne','$2y$10$JQvSTrKZLuCdyafvk1ZT.eyoS/16d5HDSgxE.be5QZhexjtJVP4Cy',0);
/*!40000 ALTER TABLE `entity_accounts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `entity_cart`
--

DROP TABLE IF EXISTS `entity_cart`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `entity_cart` (
  `CartID` int(10) NOT NULL,
  `Size` int(10) DEFAULT NULL,
  `UserID` int(10) DEFAULT NULL,
  PRIMARY KEY (`CartID`),
  KEY `UserID` (`UserID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `entity_cart`
--

LOCK TABLES `entity_cart` WRITE;
/*!40000 ALTER TABLE `entity_cart` DISABLE KEYS */;
INSERT INTO `entity_cart` VALUES (0,0,NULL);
/*!40000 ALTER TABLE `entity_cart` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `items`
--

DROP TABLE IF EXISTS `items`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `items` (
  `ItemSKU` int(10) NOT NULL AUTO_INCREMENT,
  `Name` varchar(50) DEFAULT NULL,
  `Description` varchar(255) DEFAULT NULL,
  `Genre` varchar(50) DEFAULT NULL,
  `ReleaseDate` varchar(50) DEFAULT NULL,
  `Price` float(12,0) DEFAULT NULL,
  `image` varchar(50) DEFAULT NULL,
  `numSold` int(10) DEFAULT 0,
  PRIMARY KEY (`ItemSKU`)
) ENGINE=InnoDB AUTO_INCREMENT=21 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `items`
--

LOCK TABLES `items` WRITE;
/*!40000 ALTER TABLE `items` DISABLE KEYS */;
INSERT INTO `items` VALUES (0,'Ghost of Tsushima','None',' Action',NULL,60,NULL,0),(10,'Pokemon','None','RPG',NULL,20,NULL,0),(11,'GTA','None','Action',NULL,70,NULL,0),(12,'Tekken','Some Game',NULL,NULL,41,'none',0),(13,'Tekken','Some Game',NULL,NULL,41,'none',0),(14,'Tekken','Some Game',NULL,NULL,41,'none',0),(15,'Tekken','Some Game',NULL,NULL,41,'none',0),(16,'Tekken','Some Game',NULL,NULL,41,'none',0),(17,'Tekken','Some Game',NULL,NULL,41,'none',0),(18,'Tekken','Some Game',NULL,NULL,41,'none',0),(19,'Tekken','Some Game',NULL,NULL,41,'none',0),(20,'Tekken','Some Game',NULL,NULL,41,'none',0);
/*!40000 ALTER TABLE `items` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `junction_cartitem`
--

DROP TABLE IF EXISTS `junction_cartitem`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `junction_cartitem` (
  `CartItemID` int(10) NOT NULL,
  `CartID` int(10) DEFAULT NULL,
  `ItemSKU` int(10) DEFAULT NULL,
  PRIMARY KEY (`CartItemID`),
  KEY `CartID` (`CartID`),
  KEY `ItemSKU` (`ItemSKU`),
  CONSTRAINT `junction_cartitem_ibfk_1` FOREIGN KEY (`CartID`) REFERENCES `entity_cart` (`CartID`),
  CONSTRAINT `junction_cartitem_ibfk_2` FOREIGN KEY (`ItemSKU`) REFERENCES `items` (`ItemSKU`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `junction_cartitem`
--

LOCK TABLES `junction_cartitem` WRITE;
/*!40000 ALTER TABLE `junction_cartitem` DISABLE KEYS */;
INSERT INTO `junction_cartitem` VALUES (0,0,0);
/*!40000 ALTER TABLE `junction_cartitem` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-05-25  0:01:22
