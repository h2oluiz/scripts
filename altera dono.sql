--referencias :
--http://stackoverflow.com/questions/1348126/modify-owner-on-all-tables-simultaneously-in-postgresql
--http://postgresql.nabble.com/alterar-o-dono-de-todas-tabelas-do-banco-td2047800.html
---
DO $$DECLARE r record;
DECLARE
    new_owner varchar := 'user_new';
BEGIN
    FOR r IN 
        SELECT 'ALTER TABLE '|| schemaname || '.' || tablename ||' OWNER TO '|| new_owner||';' as a
        FROM pg_tables WHERE NOT schemaname IN ('pg_catalog', 'information_schema')
        ORDER BY schemaname, tablename
    LOOP
        EXECUTE r.a;
    END LOOP;
    FOR r IN 
        SELECT 'ALTER SEQUENCE '|| sequence_schema || '.' || sequence_name ||' OWNER TO '|| new_owner||';' as a
        FROM information_schema.sequences WHERE NOT sequence_schema IN ('pg_catalog', 'information_schema')
        ORDER BY sequence_schema, sequence_name
    LOOP
        EXECUTE r.a;
    END LOOP;
   FOR r IN 
       SELECT 'ALTER VIEW '|| table_schema || '.' || table_name ||' OWNER TO '|| new_owner||';' as a
       FROM information_schema.views WHERE NOT table_schema IN ('pg_catalog', 'information_schema')
       ORDER BY table_schema, table_name
    LOOP
        EXECUTE r.a;
    END LOOP;
END$$;
