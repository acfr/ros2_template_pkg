
.. _program_listing_file_doc_docs_build_ros2_template_pkg_ros2_template_pkg_conf.py:

Program Listing for File conf.py
================================

|exhale_lsh| :ref:`Return to documentation for file <file_doc_docs_build_ros2_template_pkg_ros2_template_pkg_conf.py>` (``doc/docs_build/ros2_template_pkg/ros2_template_pkg/conf.py``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: py

   
   
   import sys
   
   
   exec(open("/home/jerome/dev_ws/src/ros2_template_pkg/ros2_template_pkg/doc/docs_build/ros2_template_pkg/ros2_template_pkg/default_sphinx_project/conf.py").read())
   
   def ensure_global(name, default):
       if name not in globals():
           globals()[name] = default
   
   
   
   ensure_global('rosdoc2_settings', {})
   ensure_global('extensions', [])
   
   if rosdoc2_settings.get('enable_autodoc', True):
       print('[rosdoc2] enabling autodoc', file=sys.stderr)
       extensions.append('sphinx.ext.autodoc')
   
   if rosdoc2_settings.get('enable_intersphinx', True):
       print('[rosdoc2] enabling intersphinx', file=sys.stderr)
       extensions.append('sphinx.ext.intersphinx')
   
   if rosdoc2_settings.get('enable_breathe', True):
       # Configure Breathe.
       # Breathe ingests the XML output from Doxygen and makes it accessible from Sphinx.
       print('[rosdoc2] enabling breathe', file=sys.stderr)
       ensure_global('breathe_projects', {})
       breathe_projects.update({
           "ros2_template_pkg Doxygen Project": "/home/jerome/dev_ws/src/ros2_template_pkg/ros2_template_pkg/doc/docs_build/ros2_template_pkg/output_staging/generated/doxygen/xml"
       })
       if breathe_projects:
           # Enable Breathe and arbitrarily select the first project.
           extensions.append('breathe')
           breathe_default_project = next(iter(breathe_projects.keys()))
   
   if rosdoc2_settings.get('enable_exhale', True):
       # Configure Exhale.
       # Exhale uses the output of Doxygen and Breathe to create easier to browse pages
       # for classes and functions documented with Doxygen.
       # This is similar to the class hierarchies and namespace listing provided by
       # Doxygen out of the box.
       print('[rosdoc2] enabling exhale', file=sys.stderr)
       extensions.append('exhale')
       ensure_global('exhale_args', {})
   
       default_exhale_specs_mapping = {
           'page': [':content-only:'],
           **dict.fromkeys(
               ['class', 'struct'],
               [':members:', ':protected-members:', ':undoc-members:']),
       }
   
       exhale_specs_mapping = rosdoc2_settings.get(
           'exhale_specs_mapping', default_exhale_specs_mapping)
   
       from exhale import utils
       exhale_args.update({
           # These arguments are required.
           "containmentFolder": "/home/jerome/dev_ws/src/ros2_template_pkg/ros2_template_pkg/doc/docs_build/ros2_template_pkg/ros2_template_pkg/default_sphinx_project/generated",
           "rootFileName": "index.rst",
           "doxygenStripFromPath": "..",
           # Suggested optional arguments.
           "createTreeView": True,
           "fullToctreeMaxDepth": 1,
           "unabridgedOrphanKinds": [],
           "fullApiSubSectionTitle": "Reference",
           # TIP: if using the sphinx-bootstrap-theme, you need
           # "treeViewIsBootstrap": True,
           "exhaleExecutesDoxygen": False,
           # Maps markdown files to the "md" lexer, and not the "markdown" lexer
           # Pygments registers "md" as a valid markdown lexer, and not "markdown"
           "lexerMapping": {r".*\.(md|markdown)$": "md",},
           "customSpecificationsMapping": utils.makeCustomSpecificationsMapping(
               lambda kind: exhale_specs_mapping.get(kind, [])),
       })
   
   if rosdoc2_settings.get('override_theme', True):
       extensions.append('sphinx_rtd_theme')
       html_theme = 'sphinx_rtd_theme'
       print(f"[rosdoc2] overriding theme to be '{html_theme}'", file=sys.stderr)
   
   if rosdoc2_settings.get('automatically_extend_intersphinx_mapping', True):
       print(f"[rosdoc2] extending intersphinx mapping", file=sys.stderr)
       if 'sphinx.ext.intersphinx' not in extensions:
           raise RuntimeError(
               "Cannot extend intersphinx mapping if 'sphinx.ext.intersphinx' "
               "has not been added to the extensions")
       ensure_global('intersphinx_mapping', {
           
       })
   
   if rosdoc2_settings.get('support_markdown', True):
       print(f"[rosdoc2] adding markdown parser", file=sys.stderr)
       # The `myst_parser` is used specifically if there are markdown files
       # in the sphinx project
       # TODO(aprotyas): Migrate files under the `include` tag in the project's Doxygen
       # configuration into the Sphinx project tree used to run the Sphinx builder in.
       extensions.append('myst_parser')
