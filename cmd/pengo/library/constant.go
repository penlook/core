package library

// Application mode
var (
	MODE_DEVELOPMENT                = 0
	MODE_PRODUCTION                 = 1
)

// Annotation
var (
	ANNOTATION_CONTROLLER_PROPERTY  =   []string {
											"@Route",
											"@Method",
											"@Template",
											"@Error",
											"@Pick",
											"@Rest",
											"@Less",
											"@Dart",
											"@Test",
										}

	ANNOTATION_MODEL_TYPE			=	[] string {
											"@Table",
											"@Document",
											"@Graph",
										}

	ANNOTATION_MODEL_PROPERTY		=   [] string {
											"@Type",
											"@Server",
											"@Port",
											"@Database",
											"@File",
											"@Charset",
											"@Test",
										}

	ANNOTATION_LIBRARY_PROPERTY		=   [] string {
											"@Export",
										}

)

// Compile pattern
var (
	PATTERN_ANNOTATION              =   "^\\@[A-Z]{1}[a-zA-Z0-9]+[\\s]+[\\w\\/\\:\"\\s]+"
	PATTERN_FUNCTION_DEFINE         =   "^\\@[A-Z]{1}[a-zA-Z0-9]+(|([\\(a-zA-Z0-9\\s,\\)]+))\\{"
	PATTERN_FUNCTION_CALL           =   "\\@[A-Z]"
	PATTERN_FILENAME_CONTROLLER     =   "[a-z_]+\\.go"
	PATTERN_CONTROLLER_MODEL        =   "\\#[A-Z]{1}[a-zA-Z0-9]+\\((|[a-zA-Z0-9,\\s\\&]+)\\)"
	PATTERN_VARIABLE_TEMPLATE       =   "([\t]+)\\$[a-z\\s]+\\=[\\s]+"
	PATTERN_VARIABLE_CONTEXT        =   "([\t]+)\\@\\@[a-z]"
	PATTERN_MODEL_TABLE             =   "\\#[A-Z]{1}[a-zA-Z0-9\\s]+(\\{|)(|\\s+)(\\}|)"
)