// Autogenerated file for halcon type HPixVal

#include "pyhirsch.h"

static void
PyHirschPixVal_dealloc(PyHirschPixVal* self)
{
    if(self->PixVal)
        delete self->PixVal;
    PyObject_Del(self);
}

static int
PyHirschPixVal_init(PyHirschPixVal *self, PyObject */*args*/, PyObject */*kwds*/)
{
    // TBD - Use PyArg_ParseTupleAndKeywords() to do special initialziation
    self->PixVal=new Halcon::HPixVal;
    return 0;
}

#include "hpixval_autogen_methods_declarations.i"

static PyMethodDef PyHirschPixVal_methods[] = {
#include "hpixval_autogen_methods_list.i"
    {NULL}  /* Sentinel */
};

PyObject *PyHirschPixVal_FromHPixVal(Halcon::HPixVal PixVal)
{
    PyHirschPixVal *v = (PyHirschPixVal*)PyObject_New(PyHirschPixVal, &PyHirschPixValType);
    v->PixVal = new Halcon::HPixVal(PixVal);
    return (PyObject*)v;
}

PyTypeObject PyHirschPixValType = {
    PyObject_HEAD_INIT(NULL)
    0,                         /*ob_size*/
    "Halcon.PyHirschPixVal",      /*tp_name*/
    sizeof(PyHirschPixVal), /*tp_basicsize*/
    0,                         /*tp_itemsize*/
    (destructor)PyHirschPixVal_dealloc,       /*tp_dealloc*/
    0,                         /*tp_print*/
    0,                         /*tp_getattr*/
    0,                         /*tp_setattr*/
    0,                         /*tp_compare*/
    0,                         /*tp_repr*/
    0,                         /*tp_as_number*/
    0,        /*tp_as_sequence*/
    0,                         /*tp_as_mapping*/
    0,                         /*tp_hash */
    0,                         /*tp_call*/
    0,                         /*tp_str*/
    0,                         /*tp_getattro*/
    0,                         /*tp_setattro*/
    0,                         /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT,        /*tp_flags*/
    "PyHirschPixVal",        /* tp_doc */
    0,		               /* tp_traverse */
    0,		               /* tp_clear */
    0,		               /* tp_richcompare */
    0,		               /* tp_weaklistoffset */
    0,		 /* tp_iter */
    0,         /* tp_iternext */
    PyHirschPixVal_methods,  /* tp_methods */
    0,                         /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc)PyHirschPixVal_init,          /* tp_init */
    0,                         /* tp_alloc */
    PyType_GenericNew,         /* tp_new */
};


void PyHirschPixValAddToModule(PyObject *m)
{
    Py_INCREF(&PyHirschPixValType);
    if (PyType_Ready(&PyHirschPixValType) < 0)
        return;
    PyModule_AddObject(m, "HPixVal", (PyObject *)&PyHirschPixValType);
}

