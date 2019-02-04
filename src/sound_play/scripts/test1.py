import rospy, os, sys
from sound_play.msg import SoundRequest

from sound_play.libsoundplay import SoundClient

def sleep(t):
    try:
        rospy.sleep(t)
    except:
        pass
if __name__ == '__main__':
    rospy.init_node('soundplay_test', anonymous = True)
    soundhandle = SoundClient()

    rospy.sleep(1)

    soundhandle.stopAll()
     #print 'say'
     #soundhandle.say('Hello world!')
     #sleep(3)
    s3 = soundhandle.voiceSound("I am following")
     print "I am following"
    s3.repeat()
    sleep(3)
    print "New API stop"
    s3.stop()
