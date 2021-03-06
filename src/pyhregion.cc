// Autogenerated file for halcon type HRegion

#include "pyhirsch.h"

static void
PyHirschRegion_dealloc(PyHirschRegion* self)
{
    if(self->Region)
        delete self->Region;
    self->ob_type->tp_free((PyObject*)self);
}

static int
PyHirschRegion_init(PyHirschRegion *self, PyObject *args, PyObject */*kwds*/)
{
    PyObject *ob;
    
    if (PyArg_ParseTuple(args,"O",&ob)) {
        if (PyHirschRegion_Check(ob))
            self->Region = new Halcon::HRegion(*(((PyHirschRegion*)ob)->Region));
        else if (PyHirschRectangle1_Check(ob)) {
            // The following convoluted code is needed to avoid crashes.
            Halcon::HRectangle1* rect = &(((PyHirschRectangle1*)ob)->Rectangle1);
            Halcon::HPoint2D ul(rect->UpperLeft());
            Halcon::HPoint2D lr(rect->LowerRight());
            Halcon::HRectangle1 r1(ul,lr);

            // Halcon::HRectangle1 r1(rect->UpperLeft(),rect->LowerRight());  // This crashes!

            self->Region = new Halcon::HRegion(Halcon::HRectangle1(ul,lr));  
        }
        //        Py_DECREF(ob);
    }
    else
        self->Region = new Halcon::HRegion();

    PyErr_Clear();

    return 0;
}

#include "hregion_autogen_methods_declarations.i"

static PyMethodDef PyHirschRegion_methods[] = {
#include "hregion_autogen_methods_list.i"
    {NULL}  /* Sentinel */
};

PyObject *PyHirschRegion_FromHRegion(Halcon::HRegion Region)
{
    PyHirschRegion *v = (PyHirschRegion*)PyObject_New(PyHirschRegion, &PyHirschRegionType);
    v->Region = new Halcon::HRegion(Region);
    return (PyObject*)v;
}

PyTypeObject PyHirschRegionType = {
    PyObject_HEAD_INIT(NULL)
    0,                         /*ob_size*/
    "Halcon.HRegion",      /*tp_name*/
    sizeof(PyHirschRegion), /*tp_basicsize*/
    0,                         /*tp_itemsize*/
    (destructor)PyHirschRegion_dealloc,       /*tp_dealloc*/
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
    "PyHirschRegion",        /* tp_doc */
    0,		               /* tp_traverse */
    0,		               /* tp_clear */
    0,		               /* tp_richcompare */
    0,		               /* tp_weaklistoffset */
    0,		 /* tp_iter */
    0,         /* tp_iternext */
    PyHirschRegion_methods,  /* tp_methods */
    0,                         /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc)PyHirschRegion_init,          /* tp_init */
    0,                         /* tp_alloc */
    PyType_GenericNew,         /* tp_new */
};


void PyHirschRegionAddToModule(PyObject *m)
{
    Py_INCREF(&PyHirschRegionType);
    if (PyType_Ready(&PyHirschRegionType) < 0)
        return;
    PyModule_AddObject(m, "HRegion", (PyObject *)&PyHirschRegionType);
}

