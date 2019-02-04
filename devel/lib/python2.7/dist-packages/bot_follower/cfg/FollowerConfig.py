## *********************************************************
## 
## File autogenerated for the bot_follower package 
## by the dynamic_reconfigure package.
## Please do not edit.
## 
## ********************************************************/

from dynamic_reconfigure.encoding import extract_params

inf = float('inf')

config_description = {'upper': 'DEFAULT', 'lower': 'groups', 'srcline': 246, 'name': 'Default', 'parent': 0, 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'cstate': 'true', 'parentname': 'Default', 'class': 'DEFAULT', 'field': 'default', 'state': True, 'parentclass': '', 'groups': [], 'parameters': [{'srcline': 293, 'description': 'The minimum x position of the points in the box.', 'max': 3.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'min_x', 'edit_method': '', 'default': -0.5, 'level': 0, 'min': -3.0, 'type': 'double'}, {'srcline': 293, 'description': 'The maximum x position of the points in the box.', 'max': 3.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'max_x', 'edit_method': '', 'default': 0.5, 'level': 0, 'min': -3.0, 'type': 'double'}, {'srcline': 293, 'description': 'The minimum y position of the points in the box.', 'max': 3.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'min_y', 'edit_method': '', 'default': -0.5, 'level': 0, 'min': -1.0, 'type': 'double'}, {'srcline': 293, 'description': 'The maximum y position of the points in the box.', 'max': 3.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'max_y', 'edit_method': '', 'default': 0.5, 'level': 0, 'min': -1.0, 'type': 'double'}, {'srcline': 293, 'description': 'The maximum z position of the points in the box.', 'max': 3.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'max_z', 'edit_method': '', 'default': 0.8, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 293, 'description': 'The distance away from the robot to hold the centroid.', 'max': 3.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'goal_z', 'edit_method': '', 'default': 0.6, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 293, 'description': 'The scaling factor for translational robot speed.', 'max': 3.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'x_scale', 'edit_method': '', 'default': 1.0, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 293, 'description': 'The scaling factor for rotational robot speed.', 'max': 10.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'z_scale', 'edit_method': '', 'default': 5.0, 'level': 0, 'min': 0.0, 'type': 'double'}], 'type': '', 'id': 0}

min = {}
max = {}
defaults = {}
level = {}
type = {}
all_level = 0

#def extract_params(config):
#    params = []
#    params.extend(config['parameters'])    
#    for group in config['groups']:
#        params.extend(extract_params(group))
#    return params

for param in extract_params(config_description):
    min[param['name']] = param['min']
    max[param['name']] = param['max']
    defaults[param['name']] = param['default']
    level[param['name']] = param['level']
    type[param['name']] = param['type']
    all_level = all_level | param['level']

