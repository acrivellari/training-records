
-- PostgreSQL stuff
SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;


-- USERS
INSERT INTO dev.users (username, name, surname, password)
VALUES ('evilcrive', 'Alberto', 'Crivellari', '71bc2adc79fc1e12e02dad6073a72efdcb4417d47bb39bc3b15bb758ffcb4f59');