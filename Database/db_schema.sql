-- delete existing tables
drop table if exists dev.users cascade;

-- delete existing schema
drop schema if exists dev cascade;

-- create schema
create schema dev;

-- create sequences

-- create domains

-- create tables
CREATE TABLE dev.users (
    id SERIAL PRIMARY KEY,
    username VARCHAR(50) NOT NULL UNIQUE,
    name VARCHAR(50) NOT NULL,
    surname VARCHAR(50) NOT NULL,
	password VARCHAR(255) NOT NULL,
    email VARCHAR(100),
    creation_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);