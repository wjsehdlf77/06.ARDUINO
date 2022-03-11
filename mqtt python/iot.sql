-- SQLite
create table SENSORS(
    ID          INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    USER        char(20),
    PLACE       char(20),
    SENSOR      char(20),
    VALUE       REAL,
    REG_DATE    DATETIME DEFAULT CURRENT_TIMESTAMP
);

drop table SENSORS;