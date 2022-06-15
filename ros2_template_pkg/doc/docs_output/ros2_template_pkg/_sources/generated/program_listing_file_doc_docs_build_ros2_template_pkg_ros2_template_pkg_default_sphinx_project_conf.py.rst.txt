
.. _program_listing_file_doc_docs_build_ros2_template_pkg_ros2_template_pkg_default_sphinx_project_conf.py:

Program Listing for File conf.py
================================

|exhale_lsh| :ref:`Return to documentation for file <file_doc_docs_build_ros2_template_pkg_ros2_template_pkg_default_sphinx_project_conf.py>` (``doc/docs_build/ros2_template_pkg/ros2_template_pkg/default_sphinx_project/conf.py``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: py

   
   
   # Configuration file for the Sphinx documentation builder.
   #
   # This file only contains a selection of the most common options. For a full
   # list see the documentation:
   # https://www.sphinx-doc.org/en/master/usage/configuration.html
   
   # -- Path setup --------------------------------------------------------------
   
   # If extensions (or modules to document with autodoc) are in another directory,
   # add these directories to sys.path here. If the directory is relative to the
   # documentation root, use os.path.abspath to make it absolute, like shown here.
   #
   # import os
   # import sys
   # sys.path.insert(0, os.path.abspath('.'))
   
   
   # -- Project information -----------------------------------------------------
   
   project = 'ros2_template_pkg'
   # TODO(tfoote) The docs say year and author but we have this and it seems more relevant.
   copyright = '2021, BSD'
   author = 'Jerome Justin'
   
   # The full version, including alpha/beta/rc tags
   release = '0.0.0'
   
   version = '0.0'
   
   
   # -- General configuration ---------------------------------------------------
   
   # Add any Sphinx extension module names here, as strings. They can be
   # extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
   # ones.
   
   extensions = [
       'sphinx_rtd_theme',
   ]
   
   # Add any paths that contain templates here, relative to this directory.
   templates_path = ['_templates']
   
   # List of patterns, relative to source directory, that match files and
   # directories to ignore when looking for source files.
   # This pattern also affects html_static_path and html_extra_path.
   exclude_patterns = []
   
   master_doc = 'index'
   
   source_suffix = {
       '.rst': 'restructuredtext',
       '.md': 'markdown',
       '.markdown': 'markdown',
   }
   
   # -- Options for HTML output -------------------------------------------------
   
   # The theme to use for HTML and HTML Help pages.  See the documentation for
   # a list of builtin themes.
   #
   
   html_theme = 'sphinx_rtd_theme'
   
   html_theme_options = {
       # Toc options
       'collapse_navigation': False,
       'sticky_navigation': True,
       'navigation_depth': -1,
       'includehidden': True,
       'titles_only': False,
   }
   
   # Add any paths that contain custom static files (such as style sheets) here,
   # relative to this directory. They are copied after the builtin static files,
   # so a file named "default.css" will overwrite the builtin "default.css".
   
   
   # -- Options for rosdoc2 -----------------------------------------------------
   
   
   rosdoc2_settings = {
       
   
       
   
       
   
       
   
       
   
       
   
       
   }
