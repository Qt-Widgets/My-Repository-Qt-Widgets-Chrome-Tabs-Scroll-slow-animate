what is this
============

QtWidgetListView is a list view, powered by Qt's Interview framework.

Unlike a traditional listview, it allows for full, easy customisation of the UI, by presenting items as regular widgets, which may be created through Qt Designer or other means.

Basically, it's like QWidget and QAbstractItemDelegate eloped, made sweet, sweet love, and had a lovechild.

You create a QtModelWidget subclass, and a QtWidgetListView instance, passing the QtWidgetListView the staticMetaObject of your QtModelWIdget subclass.

Then, you set a model on the listview, and watch in amazement as QtWidgetListView creates widgets representing the items for your model.

This allows for rich UI, done easily - no manual painting like delegates, meaning more robust, flexible, and easy to maintain code.

contact
=======

All contact to do with this code should go to:
 robin@viroteck.net

Patches, of course, are welcome.


![1](.//1.gif)
