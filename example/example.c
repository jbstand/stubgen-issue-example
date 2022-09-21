#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "structmember.h"

/**
 * @brief ExampleObject_t structure
 *
 * This structure is used to store the objects' data.
 *
 */
typedef struct {
    PyObject_HEAD // Only needed in base class
    uint32_t test; //Handle
} ExampleObject_t;

/**
 * @brief Method init docstring
 */
static const char method_example_init_doc[] =
    "init(self) -> None\n\
:Example:\n\
\n\
    >>> from example import example\n\
    >>> ex = example()\n\
    >>> ex.init()\n\
\n";
static PyObject *method_example_init(ExampleObject_t *self, PyObject *args)
{
    Py_RETURN_NONE;
}

/**
 * @brief example class members
 */
static PyMemberDef members_example[] = {
    {NULL, 0, 0, 0, NULL} // Sentinel
};

static PyMethodDef methods_example[] = {
    {"init", (PyCFunction)method_example_init, METH_NOARGS, method_example_init_doc},
    {NULL, NULL, 0, NULL} // Sentinel
};

/**
 * @brief example Init method
 */
static int Example_init(ExampleObject_t *self, PyObject *args, PyObject *kwds)
{
    // if(!PyArg_ParseTuple(args, "i", &self->loc))
    //     return -1;

    return 0;
}

PyTypeObject Example_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
        .tp_name = "example.example",
    .tp_doc = "Example Documentation",
    .tp_basicsize = sizeof(ExampleObject_t),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_init = (initproc)Example_init,
    .tp_members = members_example,
    .tp_methods = methods_example,
};

/**
 * @brief Module docstring
 */
static const char moduleDoc[] =
    "Python interface for the example library\n\
\n\
\n\
";

/**
 * @brief Module definition
 */
static PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    .m_name = "example",
    .m_doc = moduleDoc,
    .m_size = -1,
};

/**
 * @brief Module init function
 *
 * @return PyMODINIT_FUNC
 */
PyMODINIT_FUNC PyInit_example(void)
{
    PyObject *m;

    if(PyType_Ready(&Example_Type) < 0)
    {
        return NULL;
    }

    m = PyModule_Create(&module);

    if(m == NULL)
    {
        return NULL;
    }

    // Add Example class
    Py_INCREF(&Example_Type);
    if(PyModule_AddObject(m, "example", (PyObject *)&Example_Type) < 0)
    {
        Py_DECREF(&Example_Type);
        Py_DECREF(m);
        return NULL;
    }

    return m;
}
