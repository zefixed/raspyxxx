--
-- PostgreSQL database dump
--

-- Dumped from database version 15.2
-- Dumped by pg_dump version 15.2

-- Started on 2023-03-21 20:16:55

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

DROP DATABASE raspyxxx;
--
-- TOC entry 3402 (class 1262 OID 16624)
-- Name: raspyxxx; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE raspyxxx WITH TEMPLATE = template0 ENCODING = 'UTF8' LOCALE_PROVIDER = libc LOCALE = 'Russian_Russia.1251';


ALTER DATABASE raspyxxx OWNER TO postgres;

\connect raspyxxx

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

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- TOC entry 217 (class 1259 OID 16670)
-- Name: buildings; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.buildings (
    id bigint NOT NULL,
    building_address character varying NOT NULL
);


ALTER TABLE public.buildings OWNER TO postgres;

--
-- TOC entry 216 (class 1259 OID 16669)
-- Name: buildings_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.buildings_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.buildings_id_seq OWNER TO postgres;

--
-- TOC entry 3403 (class 0 OID 0)
-- Dependencies: 216
-- Name: buildings_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.buildings_id_seq OWNED BY public.buildings.id;


--
-- TOC entry 225 (class 1259 OID 16802)
-- Name: discipline; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.discipline (
    id bigint NOT NULL,
    name character varying NOT NULL
);


ALTER TABLE public.discipline OWNER TO postgres;

--
-- TOC entry 224 (class 1259 OID 16801)
-- Name: discipline_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.discipline_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.discipline_id_seq OWNER TO postgres;

--
-- TOC entry 3404 (class 0 OID 0)
-- Dependencies: 224
-- Name: discipline_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.discipline_id_seq OWNED BY public.discipline.id;


--
-- TOC entry 227 (class 1259 OID 16812)
-- Name: discipline_type; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.discipline_type (
    id bigint NOT NULL,
    name character varying NOT NULL
);


ALTER TABLE public.discipline_type OWNER TO postgres;

--
-- TOC entry 226 (class 1259 OID 16811)
-- Name: discipline_type_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.discipline_type_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.discipline_type_id_seq OWNER TO postgres;

--
-- TOC entry 3405 (class 0 OID 0)
-- Dependencies: 226
-- Name: discipline_type_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.discipline_type_id_seq OWNED BY public.discipline_type.id;


--
-- TOC entry 221 (class 1259 OID 16703)
-- Name: groups; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.groups (
    id bigint NOT NULL,
    "group" character varying NOT NULL
);


ALTER TABLE public.groups OWNER TO postgres;

--
-- TOC entry 220 (class 1259 OID 16702)
-- Name: groups_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.groups_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.groups_id_seq OWNER TO postgres;

--
-- TOC entry 3406 (class 0 OID 0)
-- Dependencies: 220
-- Name: groups_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.groups_id_seq OWNED BY public.groups.id;


--
-- TOC entry 219 (class 1259 OID 16679)
-- Name: rooms; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.rooms (
    id bigint NOT NULL,
    room_num character varying NOT NULL,
    building_id bigint NOT NULL
);


ALTER TABLE public.rooms OWNER TO postgres;

--
-- TOC entry 218 (class 1259 OID 16678)
-- Name: rooms_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.rooms_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.rooms_id_seq OWNER TO postgres;

--
-- TOC entry 3407 (class 0 OID 0)
-- Dependencies: 218
-- Name: rooms_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.rooms_id_seq OWNED BY public.rooms.id;


--
-- TOC entry 229 (class 1259 OID 16858)
-- Name: schedule; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.schedule (
    id bigint NOT NULL,
    group_id bigint NOT NULL,
    teacher_id bigint NOT NULL,
    room_id bigint NOT NULL,
    pair_id bigint NOT NULL,
    discipline_id bigint NOT NULL,
    discipline_type_id bigint NOT NULL,
    start_date date NOT NULL,
    end_date date NOT NULL,
    is_active boolean NOT NULL
);


ALTER TABLE public.schedule OWNER TO postgres;

--
-- TOC entry 228 (class 1259 OID 16857)
-- Name: schedule_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.schedule_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.schedule_id_seq OWNER TO postgres;

--
-- TOC entry 3408 (class 0 OID 0)
-- Dependencies: 228
-- Name: schedule_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.schedule_id_seq OWNED BY public.schedule.id;


--
-- TOC entry 215 (class 1259 OID 16635)
-- Name: teachers; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.teachers (
    id bigint NOT NULL,
    last_name character varying NOT NULL,
    first_name character varying NOT NULL,
    patronymic character varying
);


ALTER TABLE public.teachers OWNER TO postgres;

--
-- TOC entry 214 (class 1259 OID 16634)
-- Name: teachers_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.teachers_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.teachers_id_seq OWNER TO postgres;

--
-- TOC entry 3409 (class 0 OID 0)
-- Dependencies: 214
-- Name: teachers_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.teachers_id_seq OWNED BY public.teachers.id;


--
-- TOC entry 223 (class 1259 OID 16753)
-- Name: times; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.times (
    id bigint NOT NULL,
    start_time time without time zone NOT NULL,
    end_time time without time zone NOT NULL
);


ALTER TABLE public.times OWNER TO postgres;

--
-- TOC entry 222 (class 1259 OID 16752)
-- Name: times_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.times_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.times_id_seq OWNER TO postgres;

--
-- TOC entry 3410 (class 0 OID 0)
-- Dependencies: 222
-- Name: times_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.times_id_seq OWNED BY public.times.id;


--
-- TOC entry 3209 (class 2604 OID 16673)
-- Name: buildings id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.buildings ALTER COLUMN id SET DEFAULT nextval('public.buildings_id_seq'::regclass);


--
-- TOC entry 3213 (class 2604 OID 16805)
-- Name: discipline id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.discipline ALTER COLUMN id SET DEFAULT nextval('public.discipline_id_seq'::regclass);


--
-- TOC entry 3214 (class 2604 OID 16815)
-- Name: discipline_type id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.discipline_type ALTER COLUMN id SET DEFAULT nextval('public.discipline_type_id_seq'::regclass);


--
-- TOC entry 3211 (class 2604 OID 16706)
-- Name: groups id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.groups ALTER COLUMN id SET DEFAULT nextval('public.groups_id_seq'::regclass);


--
-- TOC entry 3210 (class 2604 OID 16682)
-- Name: rooms id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.rooms ALTER COLUMN id SET DEFAULT nextval('public.rooms_id_seq'::regclass);


--
-- TOC entry 3215 (class 2604 OID 16861)
-- Name: schedule id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.schedule ALTER COLUMN id SET DEFAULT nextval('public.schedule_id_seq'::regclass);


--
-- TOC entry 3208 (class 2604 OID 16638)
-- Name: teachers id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.teachers ALTER COLUMN id SET DEFAULT nextval('public.teachers_id_seq'::regclass);


--
-- TOC entry 3212 (class 2604 OID 16756)
-- Name: times id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.times ALTER COLUMN id SET DEFAULT nextval('public.times_id_seq'::regclass);


--
-- TOC entry 3384 (class 0 OID 16670)
-- Dependencies: 217
-- Data for Name: buildings; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.buildings (id, building_address) VALUES (1, 'ул. Б. Семёновская, д. 38');
INSERT INTO public.buildings (id, building_address) VALUES (2, 'ул. Автозаводская, д. 16');
INSERT INTO public.buildings (id, building_address) VALUES (3, 'ул. Прянишникова, 2а');
INSERT INTO public.buildings (id, building_address) VALUES (4, 'ул. Павла Корчагина, 22');
INSERT INTO public.buildings (id, building_address) VALUES (5, 'ул. Михалковская, 7');
INSERT INTO public.buildings (id, building_address) VALUES (6, 'ул. Садовая-Спасская, 6');
INSERT INTO public.buildings (id, building_address) VALUES (7, 'ул. Лефортовский Вал, 26');
INSERT INTO public.buildings (id, building_address) VALUES (8, 'ул. 1-я Дубровская, д. 16а');
INSERT INTO public.buildings (id, building_address) VALUES (9, 'Обучение LMS');
INSERT INTO public.buildings (id, building_address) VALUES (10, 'Webinar');


--
-- TOC entry 3392 (class 0 OID 16802)
-- Dependencies: 225
-- Data for Name: discipline; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.discipline (id, name) VALUES (1, 'Анализ и оценка ресурсного обеспечения полиграфического и упаковочного производства');
INSERT INTO public.discipline (id, name) VALUES (2, 'Управление качеством в послепечатных процессах');
INSERT INTO public.discipline (id, name) VALUES (3, 'Защита интеллектуальной собственности');
INSERT INTO public.discipline (id, name) VALUES (4, 'Управление проектами');
INSERT INTO public.discipline (id, name) VALUES (5, 'Правовое обеспечение качества');


--
-- TOC entry 3394 (class 0 OID 16812)
-- Dependencies: 227
-- Data for Name: discipline_type; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.discipline_type (id, name) VALUES (1, 'Лекция');
INSERT INTO public.discipline_type (id, name) VALUES (2, 'Лабораторная работа');
INSERT INTO public.discipline_type (id, name) VALUES (3, 'Практика');


--
-- TOC entry 3388 (class 0 OID 16703)
-- Dependencies: 221
-- Data for Name: groups; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.groups (id, "group") VALUES (1, '191-711');


--
-- TOC entry 3386 (class 0 OID 16679)
-- Dependencies: 219
-- Data for Name: rooms; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.rooms (id, room_num, building_id) VALUES (1, '1107', 3);
INSERT INTO public.rooms (id, room_num, building_id) VALUES (2, '2203', 3);
INSERT INTO public.rooms (id, room_num, building_id) VALUES (3, '532', 4);
INSERT INTO public.rooms (id, room_num, building_id) VALUES (4, '534', 4);
INSERT INTO public.rooms (id, room_num, building_id) VALUES (5, 'Обучение LMS', 9);
INSERT INTO public.rooms (id, room_num, building_id) VALUES (6, 'Webinar', 10);


--
-- TOC entry 3396 (class 0 OID 16858)
-- Dependencies: 229
-- Data for Name: schedule; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (1, 1, 1, 1, 2, 1, 3, '2023-02-06', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (2, 1, 1, 1, 3, 1, 3, '2023-02-06', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (3, 1, 2, 2, 4, 2, 2, '2023-02-06', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (4, 1, 2, 2, 4, 2, 2, '2023-02-06', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (5, 1, 3, 5, 1, 3, 1, '2023-03-20', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (6, 1, 3, 5, 2, 3, 1, '2023-02-06', '2023-03-02', false);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (7, 1, 3, 5, 2, 3, 1, '2023-03-20', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (8, 1, 4, 6, 3, 1, 1, '2023-02-06', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (9, 1, 4, 6, 4, 1, 1, '2023-02-06', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (10, 1, 8, 3, 2, 4, 3, '2023-02-20', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (11, 1, 8, 3, 3, 4, 3, '2023-02-20', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (12, 1, 8, 3, 4, 4, 3, '2023-02-20', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (13, 1, 5, 3, 1, 5, 1, '2023-02-06', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (14, 1, 5, 3, 2, 5, 1, '2023-02-06', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (15, 1, 2, 3, 3, 2, 1, '2023-02-06', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (16, 1, 5, 3, 1, 5, 3, '2023-02-06', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (17, 1, 5, 3, 2, 5, 3, '2023-02-06', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (18, 1, 7, 4, 3, 3, 3, '2023-02-20', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (19, 1, 7, 4, 4, 3, 3, '2023-02-20', '2023-04-02', true);


--
-- TOC entry 3382 (class 0 OID 16635)
-- Dependencies: 215
-- Data for Name: teachers; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.teachers (id, last_name, first_name, patronymic) VALUES (1, 'Ивлев', 'Сергей', 'Петрович');
INSERT INTO public.teachers (id, last_name, first_name, patronymic) VALUES (2, 'Горшкова', 'Лариса', 'Олеговна');
INSERT INTO public.teachers (id, last_name, first_name, patronymic) VALUES (3, 'Алексахина', 'Юлия', 'Владимировна');
INSERT INTO public.teachers (id, last_name, first_name, patronymic) VALUES (4, 'Митрякова', 'Ольга', 'Леонидовна');
INSERT INTO public.teachers (id, last_name, first_name, patronymic) VALUES (5, 'Петергова', 'Ангелина', 'Васильевна');
INSERT INTO public.teachers (id, last_name, first_name, patronymic) VALUES (7, 'Алексеева', 'Светлана', 'Григорьевна');
INSERT INTO public.teachers (id, last_name, first_name, patronymic) VALUES (8, 'NONE', 'NONE', 'NONE');


--
-- TOC entry 3390 (class 0 OID 16753)
-- Dependencies: 223
-- Data for Name: times; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.times (id, start_time, end_time) VALUES (1, '09:00:00', '10:30:00');
INSERT INTO public.times (id, start_time, end_time) VALUES (2, '10:40:00', '12:10:00');
INSERT INTO public.times (id, start_time, end_time) VALUES (3, '12:20:00', '13:50:00');
INSERT INTO public.times (id, start_time, end_time) VALUES (4, '14:30:00', '16:00:00');
INSERT INTO public.times (id, start_time, end_time) VALUES (5, '16:10:00', '17:40:00');
INSERT INTO public.times (id, start_time, end_time) VALUES (6, '17:50:00', '19:20:00');
INSERT INTO public.times (id, start_time, end_time) VALUES (7, '19:30:00', '21:00:00');


--
-- TOC entry 3411 (class 0 OID 0)
-- Dependencies: 216
-- Name: buildings_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.buildings_id_seq', 10, true);


--
-- TOC entry 3412 (class 0 OID 0)
-- Dependencies: 224
-- Name: discipline_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.discipline_id_seq', 5, true);


--
-- TOC entry 3413 (class 0 OID 0)
-- Dependencies: 226
-- Name: discipline_type_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.discipline_type_id_seq', 3, true);


--
-- TOC entry 3414 (class 0 OID 0)
-- Dependencies: 220
-- Name: groups_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.groups_id_seq', 1, true);


--
-- TOC entry 3415 (class 0 OID 0)
-- Dependencies: 218
-- Name: rooms_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.rooms_id_seq', 6, true);


--
-- TOC entry 3416 (class 0 OID 0)
-- Dependencies: 228
-- Name: schedule_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.schedule_id_seq', 19, true);


--
-- TOC entry 3417 (class 0 OID 0)
-- Dependencies: 214
-- Name: teachers_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.teachers_id_seq', 8, true);


--
-- TOC entry 3418 (class 0 OID 0)
-- Dependencies: 222
-- Name: times_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.times_id_seq', 7, true);


--
-- TOC entry 3219 (class 2606 OID 16677)
-- Name: buildings buildings_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.buildings
    ADD CONSTRAINT buildings_pkey PRIMARY KEY (id);


--
-- TOC entry 3227 (class 2606 OID 16809)
-- Name: discipline discipline_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.discipline
    ADD CONSTRAINT discipline_pkey PRIMARY KEY (id);


--
-- TOC entry 3229 (class 2606 OID 16819)
-- Name: discipline_type discipline_type_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.discipline_type
    ADD CONSTRAINT discipline_type_pkey PRIMARY KEY (id);


--
-- TOC entry 3223 (class 2606 OID 16710)
-- Name: groups groups_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.groups
    ADD CONSTRAINT groups_pkey PRIMARY KEY (id);


--
-- TOC entry 3221 (class 2606 OID 16686)
-- Name: rooms rooms_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.rooms
    ADD CONSTRAINT rooms_pkey PRIMARY KEY (id);


--
-- TOC entry 3231 (class 2606 OID 16863)
-- Name: schedule schedule_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.schedule
    ADD CONSTRAINT schedule_pkey PRIMARY KEY (id);


--
-- TOC entry 3217 (class 2606 OID 16642)
-- Name: teachers teachers_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.teachers
    ADD CONSTRAINT teachers_pkey PRIMARY KEY (id);


--
-- TOC entry 3225 (class 2606 OID 16758)
-- Name: times times_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.times
    ADD CONSTRAINT times_pkey PRIMARY KEY (id);


--
-- TOC entry 3232 (class 2606 OID 16687)
-- Name: rooms fk_building; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.rooms
    ADD CONSTRAINT fk_building FOREIGN KEY (building_id) REFERENCES public.buildings(id);


--
-- TOC entry 3233 (class 2606 OID 16884)
-- Name: schedule fk_discipline; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.schedule
    ADD CONSTRAINT fk_discipline FOREIGN KEY (discipline_id) REFERENCES public.discipline(id);


--
-- TOC entry 3234 (class 2606 OID 16889)
-- Name: schedule fk_discipline_type; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.schedule
    ADD CONSTRAINT fk_discipline_type FOREIGN KEY (discipline_type_id) REFERENCES public.discipline_type(id);


--
-- TOC entry 3235 (class 2606 OID 16864)
-- Name: schedule fk_group; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.schedule
    ADD CONSTRAINT fk_group FOREIGN KEY (group_id) REFERENCES public.groups(id);


--
-- TOC entry 3236 (class 2606 OID 16879)
-- Name: schedule fk_pair; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.schedule
    ADD CONSTRAINT fk_pair FOREIGN KEY (pair_id) REFERENCES public.times(id);


--
-- TOC entry 3237 (class 2606 OID 16874)
-- Name: schedule fk_room; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.schedule
    ADD CONSTRAINT fk_room FOREIGN KEY (room_id) REFERENCES public.rooms(id);


--
-- TOC entry 3238 (class 2606 OID 16869)
-- Name: schedule fk_teacher; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.schedule
    ADD CONSTRAINT fk_teacher FOREIGN KEY (teacher_id) REFERENCES public.teachers(id);


-- Completed on 2023-03-21 20:16:55

--
-- PostgreSQL database dump complete
--

