--
-- PostgreSQL database dump
--

-- Dumped from database version 15.2
-- Dumped by pg_dump version 15.2

-- Started on 2023-05-30 23:30:03

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
-- TOC entry 3446 (class 1262 OID 16624)
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
-- TOC entry 3447 (class 0 OID 0)
-- Dependencies: 216
-- Name: buildings_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.buildings_id_seq OWNED BY public.buildings.id;


--
-- TOC entry 233 (class 1259 OID 16972)
-- Name: days; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.days (
    id bigint NOT NULL,
    day character varying NOT NULL
);


ALTER TABLE public.days OWNER TO postgres;

--
-- TOC entry 232 (class 1259 OID 16971)
-- Name: days_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.days_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.days_id_seq OWNER TO postgres;

--
-- TOC entry 3448 (class 0 OID 0)
-- Dependencies: 232
-- Name: days_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.days_id_seq OWNED BY public.days.id;


--
-- TOC entry 225 (class 1259 OID 16802)
-- Name: disciplines; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.disciplines (
    id bigint NOT NULL,
    discipline character varying NOT NULL
);


ALTER TABLE public.disciplines OWNER TO postgres;

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
-- TOC entry 3449 (class 0 OID 0)
-- Dependencies: 224
-- Name: discipline_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.discipline_id_seq OWNED BY public.disciplines.id;


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
-- TOC entry 3450 (class 0 OID 0)
-- Dependencies: 226
-- Name: discipline_type_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.discipline_type_id_seq OWNED BY public.discipline_type.id;


--
-- TOC entry 237 (class 1259 OID 17325)
-- Name: exceptions; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.exceptions (
    id bigint NOT NULL,
    teacher_id bigint NOT NULL,
    exception character varying NOT NULL
);


ALTER TABLE public.exceptions OWNER TO postgres;

--
-- TOC entry 236 (class 1259 OID 17324)
-- Name: exceptions_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.exceptions_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.exceptions_id_seq OWNER TO postgres;

--
-- TOC entry 3451 (class 0 OID 0)
-- Dependencies: 236
-- Name: exceptions_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.exceptions_id_seq OWNED BY public.exceptions.id;


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
-- TOC entry 3452 (class 0 OID 0)
-- Dependencies: 220
-- Name: groups_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.groups_id_seq OWNED BY public.groups.id;


--
-- TOC entry 229 (class 1259 OID 16895)
-- Name: roles; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.roles (
    id bigint NOT NULL,
    role character varying NOT NULL
);


ALTER TABLE public.roles OWNER TO postgres;

--
-- TOC entry 228 (class 1259 OID 16894)
-- Name: roles_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.roles_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.roles_id_seq OWNER TO postgres;

--
-- TOC entry 3453 (class 0 OID 0)
-- Dependencies: 228
-- Name: roles_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.roles_id_seq OWNED BY public.roles.id;


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
-- TOC entry 3454 (class 0 OID 0)
-- Dependencies: 218
-- Name: rooms_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.rooms_id_seq OWNED BY public.rooms.id;


--
-- TOC entry 235 (class 1259 OID 16981)
-- Name: schedule; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.schedule (
    id bigint NOT NULL,
    group_id bigint NOT NULL,
    teacher_id bigint NOT NULL,
    room_id bigint NOT NULL,
    pair_id bigint NOT NULL,
    day_id bigint NOT NULL,
    discipline_id bigint NOT NULL,
    discipline_type_id bigint NOT NULL,
    start_date date NOT NULL,
    end_date date NOT NULL,
    is_active boolean NOT NULL
);


ALTER TABLE public.schedule OWNER TO postgres;

--
-- TOC entry 234 (class 1259 OID 16980)
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
-- TOC entry 3455 (class 0 OID 0)
-- Dependencies: 234
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
-- TOC entry 3456 (class 0 OID 0)
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
-- TOC entry 3457 (class 0 OID 0)
-- Dependencies: 222
-- Name: times_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.times_id_seq OWNED BY public.times.id;


--
-- TOC entry 231 (class 1259 OID 16904)
-- Name: users; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.users (
    id bigint NOT NULL,
    login character varying NOT NULL,
    password character varying NOT NULL,
    role_id bigint NOT NULL
);


ALTER TABLE public.users OWNER TO postgres;

--
-- TOC entry 230 (class 1259 OID 16903)
-- Name: users_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.users_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.users_id_seq OWNER TO postgres;

--
-- TOC entry 3458 (class 0 OID 0)
-- Dependencies: 230
-- Name: users_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.users_id_seq OWNED BY public.users.id;


--
-- TOC entry 3229 (class 2604 OID 16673)
-- Name: buildings id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.buildings ALTER COLUMN id SET DEFAULT nextval('public.buildings_id_seq'::regclass);


--
-- TOC entry 3237 (class 2604 OID 16975)
-- Name: days id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.days ALTER COLUMN id SET DEFAULT nextval('public.days_id_seq'::regclass);


--
-- TOC entry 3234 (class 2604 OID 16815)
-- Name: discipline_type id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.discipline_type ALTER COLUMN id SET DEFAULT nextval('public.discipline_type_id_seq'::regclass);


--
-- TOC entry 3233 (class 2604 OID 16805)
-- Name: disciplines id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.disciplines ALTER COLUMN id SET DEFAULT nextval('public.discipline_id_seq'::regclass);


--
-- TOC entry 3239 (class 2604 OID 17328)
-- Name: exceptions id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.exceptions ALTER COLUMN id SET DEFAULT nextval('public.exceptions_id_seq'::regclass);


--
-- TOC entry 3231 (class 2604 OID 16706)
-- Name: groups id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.groups ALTER COLUMN id SET DEFAULT nextval('public.groups_id_seq'::regclass);


--
-- TOC entry 3235 (class 2604 OID 16898)
-- Name: roles id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.roles ALTER COLUMN id SET DEFAULT nextval('public.roles_id_seq'::regclass);


--
-- TOC entry 3230 (class 2604 OID 16682)
-- Name: rooms id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.rooms ALTER COLUMN id SET DEFAULT nextval('public.rooms_id_seq'::regclass);


--
-- TOC entry 3238 (class 2604 OID 16984)
-- Name: schedule id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.schedule ALTER COLUMN id SET DEFAULT nextval('public.schedule_id_seq'::regclass);


--
-- TOC entry 3228 (class 2604 OID 16638)
-- Name: teachers id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.teachers ALTER COLUMN id SET DEFAULT nextval('public.teachers_id_seq'::regclass);


--
-- TOC entry 3232 (class 2604 OID 16756)
-- Name: times id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.times ALTER COLUMN id SET DEFAULT nextval('public.times_id_seq'::regclass);


--
-- TOC entry 3236 (class 2604 OID 16907)
-- Name: users id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users ALTER COLUMN id SET DEFAULT nextval('public.users_id_seq'::regclass);


--
-- TOC entry 3420 (class 0 OID 16670)
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
-- TOC entry 3436 (class 0 OID 16972)
-- Dependencies: 233
-- Data for Name: days; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.days (id, day) VALUES (1, 'Понедельник');
INSERT INTO public.days (id, day) VALUES (2, 'Вторник');
INSERT INTO public.days (id, day) VALUES (3, 'Среда');
INSERT INTO public.days (id, day) VALUES (4, 'Четверг');
INSERT INTO public.days (id, day) VALUES (5, 'Пятница');
INSERT INTO public.days (id, day) VALUES (6, 'Суббота');
INSERT INTO public.days (id, day) VALUES (7, 'Воскресенье');


--
-- TOC entry 3430 (class 0 OID 16812)
-- Dependencies: 227
-- Data for Name: discipline_type; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.discipline_type (id, name) VALUES (1, 'Лекция');
INSERT INTO public.discipline_type (id, name) VALUES (2, 'Лабораторная работа');
INSERT INTO public.discipline_type (id, name) VALUES (3, 'Практика');


--
-- TOC entry 3428 (class 0 OID 16802)
-- Dependencies: 225
-- Data for Name: disciplines; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.disciplines (id, discipline) VALUES (1, 'Анализ и оценка ресурсного обеспечения полиграфического и упаковочного производства');
INSERT INTO public.disciplines (id, discipline) VALUES (2, 'Управление качеством в послепечатных процессах');
INSERT INTO public.disciplines (id, discipline) VALUES (3, 'Защита интеллектуальной собственности');
INSERT INTO public.disciplines (id, discipline) VALUES (4, 'Управление проектами');
INSERT INTO public.disciplines (id, discipline) VALUES (5, 'Правовое обеспечение качества');


--
-- TOC entry 3440 (class 0 OID 17325)
-- Dependencies: 237
-- Data for Name: exceptions; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.exceptions (id, teacher_id, exception) VALUES (14, 2, '1 1 1 1 1 1 1|1 1 1 1 0 0 1|1 1 1 1 1 1 1|1 1 1 1 0 0 1|1 1 1 1 1 1 1|1 1 1 1 1 1 1');
INSERT INTO public.exceptions (id, teacher_id, exception) VALUES (13, 8, '1 1 1 1 1 1 1|1 1 1 1 1 1 1|1 1 1 1 1 0 0|1 1 1 1 1 1 1|1 1 1 1 1 1 1|1 1 1 1 1 1 1');


--
-- TOC entry 3424 (class 0 OID 16703)
-- Dependencies: 221
-- Data for Name: groups; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.groups (id, "group") VALUES (1, '191-711');
INSERT INTO public.groups (id, "group") VALUES (426, '192-112');
INSERT INTO public.groups (id, "group") VALUES (427, '202-141');
INSERT INTO public.groups (id, "group") VALUES (428, '202-121');
INSERT INTO public.groups (id, "group") VALUES (429, '202-111');
INSERT INTO public.groups (id, "group") VALUES (430, '212-121');
INSERT INTO public.groups (id, "group") VALUES (431, '222-121');
INSERT INTO public.groups (id, "group") VALUES (432, '191-111');
INSERT INTO public.groups (id, "group") VALUES (433, '191-112');
INSERT INTO public.groups (id, "group") VALUES (434, '221-812');
INSERT INTO public.groups (id, "group") VALUES (435, '221-811');
INSERT INTO public.groups (id, "group") VALUES (436, '221-813');
INSERT INTO public.groups (id, "group") VALUES (437, '221-814');
INSERT INTO public.groups (id, "group") VALUES (438, '221-821');
INSERT INTO public.groups (id, "group") VALUES (439, '221-822');
INSERT INTO public.groups (id, "group") VALUES (440, '211-811');
INSERT INTO public.groups (id, "group") VALUES (441, '211-821');
INSERT INTO public.groups (id, "group") VALUES (442, '211-822');
INSERT INTO public.groups (id, "group") VALUES (443, '201-811');
INSERT INTO public.groups (id, "group") VALUES (444, '201-812');
INSERT INTO public.groups (id, "group") VALUES (445, '201-821');
INSERT INTO public.groups (id, "group") VALUES (446, '191-811');
INSERT INTO public.groups (id, "group") VALUES (447, '191-812');
INSERT INTO public.groups (id, "group") VALUES (448, '181-811');
INSERT INTO public.groups (id, "group") VALUES (449, '181-812');
INSERT INTO public.groups (id, "group") VALUES (450, '225-821');
INSERT INTO public.groups (id, "group") VALUES (451, '215-821');
INSERT INTO public.groups (id, "group") VALUES (452, '222-821');
INSERT INTO public.groups (id, "group") VALUES (453, '222-822');
INSERT INTO public.groups (id, "group") VALUES (454, '212-821');
INSERT INTO public.groups (id, "group") VALUES (455, '202-821');
INSERT INTO public.groups (id, "group") VALUES (456, '192-821');
INSERT INTO public.groups (id, "group") VALUES (457, '212-822');
INSERT INTO public.groups (id, "group") VALUES (458, '221-631');
INSERT INTO public.groups (id, "group") VALUES (459, '221-632');
INSERT INTO public.groups (id, "group") VALUES (460, '221-633');
INSERT INTO public.groups (id, "group") VALUES (461, '221-634');
INSERT INTO public.groups (id, "group") VALUES (462, '221-635');
INSERT INTO public.groups (id, "group") VALUES (463, '211-631');
INSERT INTO public.groups (id, "group") VALUES (464, '211-632');
INSERT INTO public.groups (id, "group") VALUES (465, '211-633');
INSERT INTO public.groups (id, "group") VALUES (466, '201-911');
INSERT INTO public.groups (id, "group") VALUES (467, '222-631');
INSERT INTO public.groups (id, "group") VALUES (468, '212-631');
INSERT INTO public.groups (id, "group") VALUES (469, '202-911');
INSERT INTO public.groups (id, "group") VALUES (470, '192-931');
INSERT INTO public.groups (id, "group") VALUES (471, '221-011');
INSERT INTO public.groups (id, "group") VALUES (472, '221-012');
INSERT INTO public.groups (id, "group") VALUES (473, '221-013');
INSERT INTO public.groups (id, "group") VALUES (474, '221-021');
INSERT INTO public.groups (id, "group") VALUES (475, '221-022');
INSERT INTO public.groups (id, "group") VALUES (476, '221-023');
INSERT INTO public.groups (id, "group") VALUES (477, '211-011');
INSERT INTO public.groups (id, "group") VALUES (478, '211-012');
INSERT INTO public.groups (id, "group") VALUES (479, '211-021');
INSERT INTO public.groups (id, "group") VALUES (480, '211-022');
INSERT INTO public.groups (id, "group") VALUES (481, '211-023');
INSERT INTO public.groups (id, "group") VALUES (482, '201-011');
INSERT INTO public.groups (id, "group") VALUES (483, '224-011');
INSERT INTO public.groups (id, "group") VALUES (484, '224-021');
INSERT INTO public.groups (id, "group") VALUES (485, '202-011');
INSERT INTO public.groups (id, "group") VALUES (486, '202-021');
INSERT INTO public.groups (id, "group") VALUES (487, '192-011');
INSERT INTO public.groups (id, "group") VALUES (488, '192-021');
INSERT INTO public.groups (id, "group") VALUES (489, '224-631');
INSERT INTO public.groups (id, "group") VALUES (490, '215-631');
INSERT INTO public.groups (id, "group") VALUES (491, '221-361');
INSERT INTO public.groups (id, "group") VALUES (492, '221-362');
INSERT INTO public.groups (id, "group") VALUES (493, '221-363');
INSERT INTO public.groups (id, "group") VALUES (494, '221-364');
INSERT INTO public.groups (id, "group") VALUES (495, '221-365');
INSERT INTO public.groups (id, "group") VALUES (496, '211-324');
INSERT INTO public.groups (id, "group") VALUES (497, '211-325');
INSERT INTO public.groups (id, "group") VALUES (498, '211-326');
INSERT INTO public.groups (id, "group") VALUES (499, '211-364');
INSERT INTO public.groups (id, "group") VALUES (500, '211-365');
INSERT INTO public.groups (id, "group") VALUES (501, '201-323');
INSERT INTO public.groups (id, "group") VALUES (502, '201-341');
INSERT INTO public.groups (id, "group") VALUES (503, '201-363');
INSERT INTO public.groups (id, "group") VALUES (504, '221-325');
INSERT INTO public.groups (id, "group") VALUES (505, '221-326');
INSERT INTO public.groups (id, "group") VALUES (506, '221-327');
INSERT INTO public.groups (id, "group") VALUES (507, '221-328');
INSERT INTO public.groups (id, "group") VALUES (508, '224-341');
INSERT INTO public.groups (id, "group") VALUES (509, '224-342');
INSERT INTO public.groups (id, "group") VALUES (510, '221-324');
INSERT INTO public.groups (id, "group") VALUES (511, '211-327');
INSERT INTO public.groups (id, "group") VALUES (512, '211-361');
INSERT INTO public.groups (id, "group") VALUES (513, '211-362');
INSERT INTO public.groups (id, "group") VALUES (514, '191-113');
INSERT INTO public.groups (id, "group") VALUES (515, '201-161');
INSERT INTO public.groups (id, "group") VALUES (516, '201-152');
INSERT INTO public.groups (id, "group") VALUES (517, '201-151');
INSERT INTO public.groups (id, "group") VALUES (518, '192-421');
INSERT INTO public.groups (id, "group") VALUES (519, '201-141');
INSERT INTO public.groups (id, "group") VALUES (520, '201-121');
INSERT INTO public.groups (id, "group") VALUES (521, '202-421');
INSERT INTO public.groups (id, "group") VALUES (522, '201-111');
INSERT INTO public.groups (id, "group") VALUES (523, '212-481');
INSERT INTO public.groups (id, "group") VALUES (524, '201-112');
INSERT INTO public.groups (id, "group") VALUES (525, '181-461');
INSERT INTO public.groups (id, "group") VALUES (526, '191-451');
INSERT INTO public.groups (id, "group") VALUES (527, '211-172');
INSERT INTO public.groups (id, "group") VALUES (528, '211-171');
INSERT INTO public.groups (id, "group") VALUES (529, '211-161');
INSERT INTO public.groups (id, "group") VALUES (530, '211-151');
INSERT INTO public.groups (id, "group") VALUES (531, '211-141');
INSERT INTO public.groups (id, "group") VALUES (532, '211-121');
INSERT INTO public.groups (id, "group") VALUES (533, '211-114');
INSERT INTO public.groups (id, "group") VALUES (534, '211-113');
INSERT INTO public.groups (id, "group") VALUES (535, '201-491');
INSERT INTO public.groups (id, "group") VALUES (536, '211-112');
INSERT INTO public.groups (id, "group") VALUES (537, '211-111');
INSERT INTO public.groups (id, "group") VALUES (538, '201-481');
INSERT INTO public.groups (id, "group") VALUES (539, '201-461');
INSERT INTO public.groups (id, "group") VALUES (540, '201-451');
INSERT INTO public.groups (id, "group") VALUES (541, '221-511');
INSERT INTO public.groups (id, "group") VALUES (542, '221-171');
INSERT INTO public.groups (id, "group") VALUES (543, '201-441');
INSERT INTO public.groups (id, "group") VALUES (544, '221-512');
INSERT INTO public.groups (id, "group") VALUES (545, '221-513');
INSERT INTO public.groups (id, "group") VALUES (546, '221-161');
INSERT INTO public.groups (id, "group") VALUES (547, '201-431');
INSERT INTO public.groups (id, "group") VALUES (548, '221-151');
INSERT INTO public.groups (id, "group") VALUES (549, '221-521');
INSERT INTO public.groups (id, "group") VALUES (550, '221-141');
INSERT INTO public.groups (id, "group") VALUES (551, '201-421');
INSERT INTO public.groups (id, "group") VALUES (552, '221-114');
INSERT INTO public.groups (id, "group") VALUES (553, '221-531');
INSERT INTO public.groups (id, "group") VALUES (554, '221-113');
INSERT INTO public.groups (id, "group") VALUES (555, '221-532');
INSERT INTO public.groups (id, "group") VALUES (556, '221-112');
INSERT INTO public.groups (id, "group") VALUES (557, '201-411');
INSERT INTO public.groups (id, "group") VALUES (558, '211-511');
INSERT INTO public.groups (id, "group") VALUES (559, '221-111');
INSERT INTO public.groups (id, "group") VALUES (560, '211-512');
INSERT INTO public.groups (id, "group") VALUES (561, '211-471');
INSERT INTO public.groups (id, "group") VALUES (562, '211-521');
INSERT INTO public.groups (id, "group") VALUES (563, '211-472');
INSERT INTO public.groups (id, "group") VALUES (564, '229-561');
INSERT INTO public.groups (id, "group") VALUES (565, '211-531');
INSERT INTO public.groups (id, "group") VALUES (566, '211-451');
INSERT INTO public.groups (id, "group") VALUES (567, '211-532');
INSERT INTO public.groups (id, "group") VALUES (568, '211-441');
INSERT INTO public.groups (id, "group") VALUES (569, '22А-131');
INSERT INTO public.groups (id, "group") VALUES (570, '211-442');
INSERT INTO public.groups (id, "group") VALUES (571, '211-533');
INSERT INTO public.groups (id, "group") VALUES (572, '211-443');
INSERT INTO public.groups (id, "group") VALUES (573, '22А-121');
INSERT INTO public.groups (id, "group") VALUES (574, '22А-111');
INSERT INTO public.groups (id, "group") VALUES (575, '211-431');
INSERT INTO public.groups (id, "group") VALUES (576, '22А-911');
INSERT INTO public.groups (id, "group") VALUES (577, '211-541');
INSERT INTO public.groups (id, "group") VALUES (578, '211-421');
INSERT INTO public.groups (id, "group") VALUES (579, '211-551');
INSERT INTO public.groups (id, "group") VALUES (580, '201-511');
INSERT INTO public.groups (id, "group") VALUES (581, '211-411');
INSERT INTO public.groups (id, "group") VALUES (582, '201-531');
INSERT INTO public.groups (id, "group") VALUES (583, '221-471');
INSERT INTO public.groups (id, "group") VALUES (584, '201-541');
INSERT INTO public.groups (id, "group") VALUES (585, '221-451');
INSERT INTO public.groups (id, "group") VALUES (586, '201-542');
INSERT INTO public.groups (id, "group") VALUES (587, '201-551');
INSERT INTO public.groups (id, "group") VALUES (588, '221-441');
INSERT INTO public.groups (id, "group") VALUES (589, '221-442');
INSERT INTO public.groups (id, "group") VALUES (590, '221-431');
INSERT INTO public.groups (id, "group") VALUES (591, '221-421');
INSERT INTO public.groups (id, "group") VALUES (592, '221-411');
INSERT INTO public.groups (id, "group") VALUES (593, '191-531');
INSERT INTO public.groups (id, "group") VALUES (594, '181-531');
INSERT INTO public.groups (id, "group") VALUES (595, '212-551');
INSERT INTO public.groups (id, "group") VALUES (596, '224-511');
INSERT INTO public.groups (id, "group") VALUES (597, '224-512');
INSERT INTO public.groups (id, "group") VALUES (598, '22А-412');
INSERT INTO public.groups (id, "group") VALUES (599, '22А-411');
INSERT INTO public.groups (id, "group") VALUES (600, '224-531');
INSERT INTO public.groups (id, "group") VALUES (601, '224-541');
INSERT INTO public.groups (id, "group") VALUES (602, '22А-511');
INSERT INTO public.groups (id, "group") VALUES (603, '22А-521');
INSERT INTO public.groups (id, "group") VALUES (604, '22А-531');
INSERT INTO public.groups (id, "group") VALUES (605, '201-521');
INSERT INTO public.groups (id, "group") VALUES (606, '181-231');
INSERT INTO public.groups (id, "group") VALUES (607, '221-711');
INSERT INTO public.groups (id, "group") VALUES (608, '221-721');
INSERT INTO public.groups (id, "group") VALUES (609, '221-741');
INSERT INTO public.groups (id, "group") VALUES (610, '221-751');
INSERT INTO public.groups (id, "group") VALUES (611, '221-752');
INSERT INTO public.groups (id, "group") VALUES (612, '221-753');
INSERT INTO public.groups (id, "group") VALUES (613, '211-711');
INSERT INTO public.groups (id, "group") VALUES (614, '211-7211');
INSERT INTO public.groups (id, "group") VALUES (615, '211-741');
INSERT INTO public.groups (id, "group") VALUES (616, '211-751');
INSERT INTO public.groups (id, "group") VALUES (617, '211-752');
INSERT INTO public.groups (id, "group") VALUES (618, '211-753');
INSERT INTO public.groups (id, "group") VALUES (619, '201-711');
INSERT INTO public.groups (id, "group") VALUES (620, '201-741');
INSERT INTO public.groups (id, "group") VALUES (621, '201-751');
INSERT INTO public.groups (id, "group") VALUES (622, '201-761');
INSERT INTO public.groups (id, "group") VALUES (623, '201-762');
INSERT INTO public.groups (id, "group") VALUES (624, '224-711');
INSERT INTO public.groups (id, "group") VALUES (625, '224-741');
INSERT INTO public.groups (id, "group") VALUES (626, '224-751');
INSERT INTO public.groups (id, "group") VALUES (627, '225-761');
INSERT INTO public.groups (id, "group") VALUES (628, '215-741');
INSERT INTO public.groups (id, "group") VALUES (629, '222-751');
INSERT INTO public.groups (id, "group") VALUES (630, '192-761');
INSERT INTO public.groups (id, "group") VALUES (631, '221-371');
INSERT INTO public.groups (id, "group") VALUES (632, '221-372');
INSERT INTO public.groups (id, "group") VALUES (633, '221-373');
INSERT INTO public.groups (id, "group") VALUES (634, '221-374');
INSERT INTO public.groups (id, "group") VALUES (635, '221-375');
INSERT INTO public.groups (id, "group") VALUES (636, '221-376');
INSERT INTO public.groups (id, "group") VALUES (637, '221-377');
INSERT INTO public.groups (id, "group") VALUES (638, '221-378');
INSERT INTO public.groups (id, "group") VALUES (639, '221-379');
INSERT INTO public.groups (id, "group") VALUES (640, '221-3710');
INSERT INTO public.groups (id, "group") VALUES (641, '221-3711');
INSERT INTO public.groups (id, "group") VALUES (642, '221-3712');
INSERT INTO public.groups (id, "group") VALUES (643, '211-721');
INSERT INTO public.groups (id, "group") VALUES (644, '211-722');
INSERT INTO public.groups (id, "group") VALUES (645, '211-723');
INSERT INTO public.groups (id, "group") VALUES (646, '211-724');
INSERT INTO public.groups (id, "group") VALUES (647, '211-725');
INSERT INTO public.groups (id, "group") VALUES (648, '211-726');
INSERT INTO public.groups (id, "group") VALUES (649, '211-727');
INSERT INTO public.groups (id, "group") VALUES (650, '211-728');
INSERT INTO public.groups (id, "group") VALUES (651, '211-729');
INSERT INTO public.groups (id, "group") VALUES (652, '211-7210');
INSERT INTO public.groups (id, "group") VALUES (653, '211-7212');
INSERT INTO public.groups (id, "group") VALUES (654, '201-721');
INSERT INTO public.groups (id, "group") VALUES (655, '201-722');
INSERT INTO public.groups (id, "group") VALUES (656, '201-723');
INSERT INTO public.groups (id, "group") VALUES (657, '201-724');
INSERT INTO public.groups (id, "group") VALUES (658, '201-725');
INSERT INTO public.groups (id, "group") VALUES (659, '201-726');
INSERT INTO public.groups (id, "group") VALUES (660, '224-371');
INSERT INTO public.groups (id, "group") VALUES (661, '224-372');
INSERT INTO public.groups (id, "group") VALUES (662, '202-721');
INSERT INTO public.groups (id, "group") VALUES (663, '192-721');
INSERT INTO public.groups (id, "group") VALUES (664, '191-231');
INSERT INTO public.groups (id, "group") VALUES (665, '201-291');
INSERT INTO public.groups (id, "group") VALUES (666, '201-281');
INSERT INTO public.groups (id, "group") VALUES (667, '201-271');
INSERT INTO public.groups (id, "group") VALUES (668, '201-261');
INSERT INTO public.groups (id, "group") VALUES (669, '201-251');
INSERT INTO public.groups (id, "group") VALUES (670, '201-241');
INSERT INTO public.groups (id, "group") VALUES (671, '201-231');
INSERT INTO public.groups (id, "group") VALUES (672, '201-222');
INSERT INTO public.groups (id, "group") VALUES (673, '201-221');
INSERT INTO public.groups (id, "group") VALUES (674, '201-211');
INSERT INTO public.groups (id, "group") VALUES (675, '211-291');
INSERT INTO public.groups (id, "group") VALUES (676, '211-281');
INSERT INTO public.groups (id, "group") VALUES (677, '211-812');
INSERT INTO public.groups (id, "group") VALUES (678, '211-271');
INSERT INTO public.groups (id, "group") VALUES (679, '211-261');
INSERT INTO public.groups (id, "group") VALUES (680, '211-813');
INSERT INTO public.groups (id, "group") VALUES (681, '211-251');
INSERT INTO public.groups (id, "group") VALUES (682, '211-242');
INSERT INTO public.groups (id, "group") VALUES (683, '211-241');
INSERT INTO public.groups (id, "group") VALUES (684, '211-231');
INSERT INTO public.groups (id, "group") VALUES (685, '211-222');
INSERT INTO public.groups (id, "group") VALUES (686, '211-223');
INSERT INTO public.groups (id, "group") VALUES (687, '211-221');
INSERT INTO public.groups (id, "group") VALUES (688, '211-211');
INSERT INTO public.groups (id, "group") VALUES (689, '221-291');
INSERT INTO public.groups (id, "group") VALUES (690, '221-281');
INSERT INTO public.groups (id, "group") VALUES (691, '221-271');
INSERT INTO public.groups (id, "group") VALUES (692, '221-261');
INSERT INTO public.groups (id, "group") VALUES (693, '221-251');
INSERT INTO public.groups (id, "group") VALUES (694, '221-241');
INSERT INTO public.groups (id, "group") VALUES (695, '221-242');
INSERT INTO public.groups (id, "group") VALUES (696, '221-223');
INSERT INTO public.groups (id, "group") VALUES (697, '221-222');
INSERT INTO public.groups (id, "group") VALUES (698, '221-221');
INSERT INTO public.groups (id, "group") VALUES (699, '221-201');
INSERT INTO public.groups (id, "group") VALUES (700, '225-281');
INSERT INTO public.groups (id, "group") VALUES (701, '224-291');
INSERT INTO public.groups (id, "group") VALUES (702, '224-251');
INSERT INTO public.groups (id, "group") VALUES (703, '224-224');
INSERT INTO public.groups (id, "group") VALUES (704, '224-223');
INSERT INTO public.groups (id, "group") VALUES (705, '224-222');
INSERT INTO public.groups (id, "group") VALUES (706, '224-221');
INSERT INTO public.groups (id, "group") VALUES (707, '192-241');
INSERT INTO public.groups (id, "group") VALUES (708, '192-221');
INSERT INTO public.groups (id, "group") VALUES (709, '202-241');
INSERT INTO public.groups (id, "group") VALUES (710, '202-221');
INSERT INTO public.groups (id, "group") VALUES (711, '212-241');
INSERT INTO public.groups (id, "group") VALUES (712, '212-221');
INSERT INTO public.groups (id, "group") VALUES (713, '208-641');
INSERT INTO public.groups (id, "group") VALUES (714, '208-611');
INSERT INTO public.groups (id, "group") VALUES (715, '208-642');
INSERT INTO public.groups (id, "group") VALUES (716, '202-611');
INSERT INTO public.groups (id, "group") VALUES (717, '201-641');
INSERT INTO public.groups (id, "group") VALUES (718, '201-622');
INSERT INTO public.groups (id, "group") VALUES (719, '201-621');
INSERT INTO public.groups (id, "group") VALUES (720, '201-611');
INSERT INTO public.groups (id, "group") VALUES (721, '218-641');
INSERT INTO public.groups (id, "group") VALUES (722, '218-611');
INSERT INTO public.groups (id, "group") VALUES (723, '215-662');
INSERT INTO public.groups (id, "group") VALUES (724, '212-641');
INSERT INTO public.groups (id, "group") VALUES (725, '212-621');
INSERT INTO public.groups (id, "group") VALUES (726, '212-611');
INSERT INTO public.groups (id, "group") VALUES (727, '211-641');
INSERT INTO public.groups (id, "group") VALUES (728, '211-621');
INSERT INTO public.groups (id, "group") VALUES (729, '211-612');
INSERT INTO public.groups (id, "group") VALUES (730, '211-611');
INSERT INTO public.groups (id, "group") VALUES (731, '224-651');
INSERT INTO public.groups (id, "group") VALUES (732, '222-641');
INSERT INTO public.groups (id, "group") VALUES (733, '222-642');
INSERT INTO public.groups (id, "group") VALUES (734, '222-611');
INSERT INTO public.groups (id, "group") VALUES (735, '222-612');
INSERT INTO public.groups (id, "group") VALUES (736, '225-631');
INSERT INTO public.groups (id, "group") VALUES (737, '221-611');
INSERT INTO public.groups (id, "group") VALUES (738, '221-621');
INSERT INTO public.groups (id, "group") VALUES (739, '192-621');
INSERT INTO public.groups (id, "group") VALUES (740, '221-3210');
INSERT INTO public.groups (id, "group") VALUES (741, '221-329');
INSERT INTO public.groups (id, "group") VALUES (742, '191-331');
INSERT INTO public.groups (id, "group") VALUES (743, '224-351');
INSERT INTO public.groups (id, "group") VALUES (744, '221-331');
INSERT INTO public.groups (id, "group") VALUES (745, '221-332');
INSERT INTO public.groups (id, "group") VALUES (746, '221-351');
INSERT INTO public.groups (id, "group") VALUES (747, '221-352');
INSERT INTO public.groups (id, "group") VALUES (748, '221-353');
INSERT INTO public.groups (id, "group") VALUES (749, '201-021');
INSERT INTO public.groups (id, "group") VALUES (750, '224-321');
INSERT INTO public.groups (id, "group") VALUES (751, '224-322');
INSERT INTO public.groups (id, "group") VALUES (752, '221-321');
INSERT INTO public.groups (id, "group") VALUES (753, '221-322');
INSERT INTO public.groups (id, "group") VALUES (754, '221-323');
INSERT INTO public.groups (id, "group") VALUES (755, '211-321');
INSERT INTO public.groups (id, "group") VALUES (756, '211-322');
INSERT INTO public.groups (id, "group") VALUES (757, '211-323');
INSERT INTO public.groups (id, "group") VALUES (758, '211-331');
INSERT INTO public.groups (id, "group") VALUES (759, '211-351');
INSERT INTO public.groups (id, "group") VALUES (760, '211-352');
INSERT INTO public.groups (id, "group") VALUES (761, '201-321');
INSERT INTO public.groups (id, "group") VALUES (762, '201-322');
INSERT INTO public.groups (id, "group") VALUES (763, '201-331');
INSERT INTO public.groups (id, "group") VALUES (764, '201-351');
INSERT INTO public.groups (id, "group") VALUES (765, '201-361');
INSERT INTO public.groups (id, "group") VALUES (766, '224-211');
INSERT INTO public.groups (id, "group") VALUES (767, '22А-621');
INSERT INTO public.groups (id, "group") VALUES (768, '22А-811');
INSERT INTO public.groups (id, "group") VALUES (769, '22А-812');
INSERT INTO public.groups (id, "group") VALUES (770, '222-221');
INSERT INTO public.groups (id, "group") VALUES (771, '214-223');
INSERT INTO public.groups (id, "group") VALUES (772, '214-225');
INSERT INTO public.groups (id, "group") VALUES (773, '224-911 ПИШ');
INSERT INTO public.groups (id, "group") VALUES (774, '224-912 ПИШ');
INSERT INTO public.groups (id, "group") VALUES (775, '224-921 ПИШ');
INSERT INTO public.groups (id, "group") VALUES (776, '224-311');
INSERT INTO public.groups (id, "group") VALUES (777, '22А-211');
INSERT INTO public.groups (id, "group") VALUES (778, '22А-212');
INSERT INTO public.groups (id, "group") VALUES (779, '22А-213');
INSERT INTO public.groups (id, "group") VALUES (780, '22А-221');
INSERT INTO public.groups (id, "group") VALUES (781, '22А-222');
INSERT INTO public.groups (id, "group") VALUES (782, '22А-223');
INSERT INTO public.groups (id, "group") VALUES (783, '22А-241');
INSERT INTO public.groups (id, "group") VALUES (784, '213-631');
INSERT INTO public.groups (id, "group") VALUES (785, '213-632');
INSERT INTO public.groups (id, "group") VALUES (786, '223-631');
INSERT INTO public.groups (id, "group") VALUES (787, '223-011');
INSERT INTO public.groups (id, "group") VALUES (788, '223-021');
INSERT INTO public.groups (id, "group") VALUES (789, '213-011');
INSERT INTO public.groups (id, "group") VALUES (790, '213-012');
INSERT INTO public.groups (id, "group") VALUES (791, '213-021');
INSERT INTO public.groups (id, "group") VALUES (792, '225-651');
INSERT INTO public.groups (id, "group") VALUES (793, '225-652');
INSERT INTO public.groups (id, "group") VALUES (794, '22А-311');
INSERT INTO public.groups (id, "group") VALUES (795, '22А-312');
INSERT INTO public.groups (id, "group") VALUES (796, '22А-313');
INSERT INTO public.groups (id, "group") VALUES (797, '22А-314');
INSERT INTO public.groups (id, "group") VALUES (798, '223-731');
INSERT INTO public.groups (id, "group") VALUES (799, '223-371');
INSERT INTO public.groups (id, "group") VALUES (800, '223-372');
INSERT INTO public.groups (id, "group") VALUES (801, '223-321');
INSERT INTO public.groups (id, "group") VALUES (802, '223-322');
INSERT INTO public.groups (id, "group") VALUES (803, '223-221');
INSERT INTO public.groups (id, "group") VALUES (804, '223-223');
INSERT INTO public.groups (id, "group") VALUES (805, '223-222');
INSERT INTO public.groups (id, "group") VALUES (806, '226-211');
INSERT INTO public.groups (id, "group") VALUES (807, '223-231');
INSERT INTO public.groups (id, "group") VALUES (808, '226-231');
INSERT INTO public.groups (id, "group") VALUES (809, '222-231');
INSERT INTO public.groups (id, "group") VALUES (810, '223-111');
INSERT INTO public.groups (id, "group") VALUES (811, '223-121');
INSERT INTO public.groups (id, "group") VALUES (812, '223-461');
INSERT INTO public.groups (id, "group") VALUES (813, '223-151');
INSERT INTO public.groups (id, "group") VALUES (814, '226-511');
INSERT INTO public.groups (id, "group") VALUES (815, '223-421');
INSERT INTO public.groups (id, "group") VALUES (816, '223-431');
INSERT INTO public.groups (id, "group") VALUES (817, '226-431');
INSERT INTO public.groups (id, "group") VALUES (818, '226-651');
INSERT INTO public.groups (id, "group") VALUES (819, '22А-011');
INSERT INTO public.groups (id, "group") VALUES (820, '22А-012');
INSERT INTO public.groups (id, "group") VALUES (821, '223-462');
INSERT INTO public.groups (id, "group") VALUES (822, '22А-231');
INSERT INTO public.groups (id, "group") VALUES (823, '227-421');
INSERT INTO public.groups (id, "group") VALUES (824, '227-461');
INSERT INTO public.groups (id, "group") VALUES (825, '21Б-221');
INSERT INTO public.groups (id, "group") VALUES (826, '21Б-141');
INSERT INTO public.groups (id, "group") VALUES (827, '201-325');
INSERT INTO public.groups (id, "group") VALUES (828, '21А-141');
INSERT INTO public.groups (id, "group") VALUES (829, '21А-131');
INSERT INTO public.groups (id, "group") VALUES (830, '21А-121');
INSERT INTO public.groups (id, "group") VALUES (831, '21А-111');
INSERT INTO public.groups (id, "group") VALUES (832, '21А-521');
INSERT INTO public.groups (id, "group") VALUES (833, '21А-531');
INSERT INTO public.groups (id, "group") VALUES (834, '21А-541');
INSERT INTO public.groups (id, "group") VALUES (835, '215-661');
INSERT INTO public.groups (id, "group") VALUES (836, '224-632');
INSERT INTO public.groups (id, "group") VALUES (837, '21А-811');
INSERT INTO public.groups (id, "group") VALUES (838, '21А-812');
INSERT INTO public.groups (id, "group") VALUES (839, '21А-211');
INSERT INTO public.groups (id, "group") VALUES (840, '21А-212');
INSERT INTO public.groups (id, "group") VALUES (841, '21А-213');
INSERT INTO public.groups (id, "group") VALUES (842, '21А-214');
INSERT INTO public.groups (id, "group") VALUES (843, '21А-215');
INSERT INTO public.groups (id, "group") VALUES (844, '21А-221');
INSERT INTO public.groups (id, "group") VALUES (845, '21А-222');
INSERT INTO public.groups (id, "group") VALUES (846, '21А-223');
INSERT INTO public.groups (id, "group") VALUES (847, '21А-231');
INSERT INTO public.groups (id, "group") VALUES (848, '21А-232');
INSERT INTO public.groups (id, "group") VALUES (849, '21А-241');


--
-- TOC entry 3432 (class 0 OID 16895)
-- Dependencies: 229
-- Data for Name: roles; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.roles (id, role) VALUES (2, 'Преподаватель');
INSERT INTO public.roles (id, role) VALUES (3, 'Методист');
INSERT INTO public.roles (id, role) VALUES (1, 'Студент');


--
-- TOC entry 3422 (class 0 OID 16679)
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
-- TOC entry 3438 (class 0 OID 16981)
-- Dependencies: 235
-- Data for Name: schedule; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, day_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (1, 1, 1, 1, 2, 1, 1, 3, '2023-02-06', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, day_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (2, 1, 1, 1, 3, 1, 1, 3, '2023-02-06', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, day_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (3, 1, 2, 2, 4, 1, 2, 2, '2023-02-06', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, day_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (4, 1, 2, 2, 4, 1, 2, 2, '2023-02-06', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, day_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (5, 1, 3, 5, 1, 2, 3, 1, '2023-03-20', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, day_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (6, 1, 3, 5, 2, 2, 3, 1, '2023-02-06', '2023-03-02', false);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, day_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (7, 1, 3, 5, 2, 2, 3, 1, '2023-03-20', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, day_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (8, 1, 4, 6, 3, 2, 1, 1, '2023-02-06', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, day_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (9, 1, 4, 6, 4, 2, 1, 1, '2023-02-06', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, day_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (10, 1, 8, 3, 2, 3, 4, 3, '2023-02-20', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, day_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (11, 1, 8, 3, 3, 3, 4, 3, '2023-02-20', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, day_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (12, 1, 8, 3, 4, 3, 4, 3, '2023-02-20', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, day_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (13, 1, 5, 3, 1, 4, 5, 1, '2023-02-06', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, day_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (14, 1, 5, 3, 2, 4, 5, 1, '2023-02-06', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, day_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (15, 1, 2, 3, 3, 4, 2, 1, '2023-02-06', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, day_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (16, 1, 5, 3, 1, 5, 5, 3, '2023-02-06', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, day_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (17, 1, 5, 3, 2, 5, 5, 3, '2023-02-06', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, day_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (18, 1, 7, 4, 3, 5, 3, 3, '2023-02-20', '2023-04-02', true);
INSERT INTO public.schedule (id, group_id, teacher_id, room_id, pair_id, day_id, discipline_id, discipline_type_id, start_date, end_date, is_active) VALUES (19, 1, 7, 4, 4, 5, 3, 3, '2023-02-20', '2023-04-02', true);


--
-- TOC entry 3418 (class 0 OID 16635)
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
-- TOC entry 3426 (class 0 OID 16753)
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
-- TOC entry 3434 (class 0 OID 16904)
-- Dependencies: 231
-- Data for Name: users; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.users (id, login, password, role_id) VALUES (2, 'teacher_login', 'teacher_password', 2);
INSERT INTO public.users (id, login, password, role_id) VALUES (3, 'metodist_login', 'metodist_password', 3);
INSERT INTO public.users (id, login, password, role_id) VALUES (8, '2', '2', 2);
INSERT INTO public.users (id, login, password, role_id) VALUES (19, '3', '3', 3);
INSERT INTO public.users (id, login, password, role_id) VALUES (1, 'student_login', 'student_password', 1);
INSERT INTO public.users (id, login, password, role_id) VALUES (13, '1', '1', 1);


--
-- TOC entry 3459 (class 0 OID 0)
-- Dependencies: 216
-- Name: buildings_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.buildings_id_seq', 11, true);


--
-- TOC entry 3460 (class 0 OID 0)
-- Dependencies: 232
-- Name: days_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.days_id_seq', 7, true);


--
-- TOC entry 3461 (class 0 OID 0)
-- Dependencies: 224
-- Name: discipline_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.discipline_id_seq', 7, true);


--
-- TOC entry 3462 (class 0 OID 0)
-- Dependencies: 226
-- Name: discipline_type_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.discipline_type_id_seq', 3, true);


--
-- TOC entry 3463 (class 0 OID 0)
-- Dependencies: 236
-- Name: exceptions_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.exceptions_id_seq', 14, true);


--
-- TOC entry 3464 (class 0 OID 0)
-- Dependencies: 220
-- Name: groups_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.groups_id_seq', 1284, true);


--
-- TOC entry 3465 (class 0 OID 0)
-- Dependencies: 228
-- Name: roles_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.roles_id_seq', 1, false);


--
-- TOC entry 3466 (class 0 OID 0)
-- Dependencies: 218
-- Name: rooms_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.rooms_id_seq', 6, true);


--
-- TOC entry 3467 (class 0 OID 0)
-- Dependencies: 234
-- Name: schedule_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.schedule_id_seq', 1, false);


--
-- TOC entry 3468 (class 0 OID 0)
-- Dependencies: 214
-- Name: teachers_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.teachers_id_seq', 10, true);


--
-- TOC entry 3469 (class 0 OID 0)
-- Dependencies: 222
-- Name: times_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.times_id_seq', 7, true);


--
-- TOC entry 3470 (class 0 OID 0)
-- Dependencies: 230
-- Name: users_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.users_id_seq', 25, true);


--
-- TOC entry 3243 (class 2606 OID 16677)
-- Name: buildings buildings_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.buildings
    ADD CONSTRAINT buildings_pkey PRIMARY KEY (id);


--
-- TOC entry 3260 (class 2606 OID 16979)
-- Name: days days_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.days
    ADD CONSTRAINT days_pkey PRIMARY KEY (id);


--
-- TOC entry 3252 (class 2606 OID 16809)
-- Name: disciplines discipline_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.disciplines
    ADD CONSTRAINT discipline_pkey PRIMARY KEY (id);


--
-- TOC entry 3254 (class 2606 OID 16819)
-- Name: discipline_type discipline_type_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.discipline_type
    ADD CONSTRAINT discipline_type_pkey PRIMARY KEY (id);


--
-- TOC entry 3264 (class 2606 OID 17332)
-- Name: exceptions exceptions_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.exceptions
    ADD CONSTRAINT exceptions_pkey PRIMARY KEY (id);


--
-- TOC entry 3248 (class 2606 OID 16710)
-- Name: groups groups_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.groups
    ADD CONSTRAINT groups_pkey PRIMARY KEY (id);


--
-- TOC entry 3256 (class 2606 OID 16902)
-- Name: roles roles_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.roles
    ADD CONSTRAINT roles_pkey PRIMARY KEY (id);


--
-- TOC entry 3245 (class 2606 OID 16686)
-- Name: rooms rooms_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.rooms
    ADD CONSTRAINT rooms_pkey PRIMARY KEY (id);


--
-- TOC entry 3262 (class 2606 OID 16986)
-- Name: schedule schedule_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.schedule
    ADD CONSTRAINT schedule_pkey PRIMARY KEY (id);


--
-- TOC entry 3241 (class 2606 OID 16642)
-- Name: teachers teachers_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.teachers
    ADD CONSTRAINT teachers_pkey PRIMARY KEY (id);


--
-- TOC entry 3250 (class 2606 OID 16758)
-- Name: times times_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.times
    ADD CONSTRAINT times_pkey PRIMARY KEY (id);


--
-- TOC entry 3258 (class 2606 OID 16911)
-- Name: users users_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_pkey PRIMARY KEY (id);


--
-- TOC entry 3246 (class 1259 OID 17422)
-- Name: group; Type: INDEX; Schema: public; Owner: postgres
--

CREATE UNIQUE INDEX "group" ON public.groups USING btree ("group");


--
-- TOC entry 3274 (class 2606 OID 17338)
-- Name: exceptions exceptions_teacher_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.exceptions
    ADD CONSTRAINT exceptions_teacher_id_fkey FOREIGN KEY (teacher_id) REFERENCES public.teachers(id) ON UPDATE CASCADE;


--
-- TOC entry 3265 (class 2606 OID 17343)
-- Name: rooms fk_building; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.rooms
    ADD CONSTRAINT fk_building FOREIGN KEY (building_id) REFERENCES public.buildings(id) ON UPDATE CASCADE;


--
-- TOC entry 3267 (class 2606 OID 17353)
-- Name: schedule fk_day; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.schedule
    ADD CONSTRAINT fk_day FOREIGN KEY (day_id) REFERENCES public.days(id) ON UPDATE CASCADE;


--
-- TOC entry 3268 (class 2606 OID 17358)
-- Name: schedule fk_discipline; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.schedule
    ADD CONSTRAINT fk_discipline FOREIGN KEY (discipline_id) REFERENCES public.disciplines(id) ON UPDATE CASCADE;


--
-- TOC entry 3269 (class 2606 OID 17363)
-- Name: schedule fk_discipline_type; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.schedule
    ADD CONSTRAINT fk_discipline_type FOREIGN KEY (discipline_type_id) REFERENCES public.discipline_type(id) ON UPDATE CASCADE;


--
-- TOC entry 3270 (class 2606 OID 17368)
-- Name: schedule fk_group; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.schedule
    ADD CONSTRAINT fk_group FOREIGN KEY (group_id) REFERENCES public.groups(id) ON UPDATE CASCADE;


--
-- TOC entry 3271 (class 2606 OID 17373)
-- Name: schedule fk_pair; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.schedule
    ADD CONSTRAINT fk_pair FOREIGN KEY (pair_id) REFERENCES public.times(id) ON UPDATE CASCADE;


--
-- TOC entry 3266 (class 2606 OID 17348)
-- Name: users fk_role; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT fk_role FOREIGN KEY (role_id) REFERENCES public.roles(id) ON UPDATE CASCADE;


--
-- TOC entry 3272 (class 2606 OID 17378)
-- Name: schedule fk_room; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.schedule
    ADD CONSTRAINT fk_room FOREIGN KEY (room_id) REFERENCES public.rooms(id) ON UPDATE CASCADE;


--
-- TOC entry 3273 (class 2606 OID 17383)
-- Name: schedule fk_teacher; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.schedule
    ADD CONSTRAINT fk_teacher FOREIGN KEY (teacher_id) REFERENCES public.teachers(id) ON UPDATE CASCADE;


-- Completed on 2023-05-30 23:30:03

--
-- PostgreSQL database dump complete
--

