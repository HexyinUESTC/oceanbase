CREATE OR REPLACE TYPE JSON_ARRAY_T OID '300025' AS OPAQUE
(
  STATIC FUNCTION parse(jsn VARCHAR2) return JSON_ARRAY_T,
  STATIC FUNCTION parse(jsn CLOB)     return JSON_ARRAY_T,
  STATIC FUNCTION parse(jsn BLOB)     return JSON_ARRAY_T,

  CONSTRUCTOR FUNCTION JSON_ARRAY_T RETURN SELF AS RESULT,
  CONSTRUCTOR FUNCTION JSON_ARRAY_T(o JSON_ELEMENT_T) RETURN SELF AS RESULT,
  CONSTRUCTOR FUNCTION JSON_ARRAY_T(o JSON_ARRAY_T) RETURN SELF AS RESULT,
  CONSTRUCTOR FUNCTION JSON_ARRAY_T(jsn VARCHAR2) RETURN SELF AS RESULT,
  CONSTRUCTOR FUNCTION JSON_ARRAY_T(jsn CLOB) RETURN SELF AS RESULT,
  CONSTRUCTOR FUNCTION JSON_ARRAY_T(jsn BLOB) RETURN SELF AS RESULT,

  MEMBER PROCEDURE on_Error(val NUMBER),
  MEMBER FUNCTION get(pos NUMBER) return JSON_ELEMENT_T,
  MEMBER FUNCTION get_Type(pos NUMBER) return VARCHAR2,
  MEMBER FUNCTION get_Size RETURN NUMBER,
  MEMBER FUNCTION to_String RETURN VARCHAR2,
  MEMBER FUNCTION clone RETURN JSON_ARRAY_T
);
//