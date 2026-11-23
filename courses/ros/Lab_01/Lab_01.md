# Lab 1 — Explore ROS 2 nodes and topics

Use the ROS 2 `image_tools` demo to stream a generated test image. You’ll inspect the camera and viewer from the terminal, trace the image stream in `rqt_graph`, and change the topic name to see what happens to the connection.

Complete the [ROS 2 Setup Guide](../setup_guide_ros2.md) before starting. Run the commands in Ubuntu Bash with access to a graphical desktop or Linux GUI windows. If your terminal does not load ROS 2 automatically, run `source /opt/ros/lyrical/setup.bash` in each terminal. The demo uses a generated image of a burger and works without a webcam.

In every section, document your answers in a markdown file or other fitting format. Include screenshots of the viewer and graph when requested.

## 1. Start the simulated camera and image viewer

In terminal 1, start the camera node in `burger_mode` and leave it running.

```bash
ros2 run image_tools cam2image --ros-args -p burger_mode:=true
```

In terminal 2, run the executable called `showimage` of the package `image_tools`.

### Documentation
- Describe what appears in the viewer
- Identify which process is the publisher and which is the subscriber

## 2. Inspect the nodes and topic

A **node** is a running ROS 2 component. A **topic** is a named channel for messages. A publisher sends messages to a topic, and a subscriber receives them from that topic.

In terminal 3, try to find the answer for the following questions and document the results.

- Which command lists all nodes? Document the output and identify the two running nodes.
- Which command lists all topics and their message types? Document the output and explain where exactly topics and message types are shown.
- Which command shows where a node publishes and subscribes? Document the output for both nodes and explain where in the output you see the subscription and publication information.
- Which command shows the details of the message type? Document the output for the message type of the topic `/image`.
- Use another terminal to output and document the width, height, and encoding of the image messages.

## 3. Read the graph

In terminal 4, launch the graphical tool.

```bash
ros2 run rqt_graph rqt_graph
```

Select **Nodes/Topics (active)** in the graph mode menu and click **Refresh** (the circular arrow). Find the two demo nodes and `/image`.

- Make a screenshot of the graph and add it to your documentation.
- Describe what the graph shows and which forms represent nodes and topics.

## 4. Reconnect the viewer on a different topic

Leave the viewer running in terminal 2. Stop the camera with **Ctrl+C** in terminal 1, then restart it with `-r` to remap its output topic from `/image` to `/lab_camera`.

```bash
ros2 run image_tools cam2image --ros-args -p burger_mode:=true -r /image:=/lab_camera
```

The viewer may still show the last frame it received. Check terminal 2 for new receive logs, refresh `rqt_graph`, and compare the publisher and subscription counts in terminal 3.

```bash
ros2 topic info /image
ros2 topic info /lab_camera
```

Stop the viewer with **Ctrl+C** in terminal 2, then restart it with the same topic remapping.

```bash
ros2 run image_tools showimage --ros-args -r /image:=/lab_camera
```

Confirm that the viewer is receiving frames again and refresh `rqt_graph`.

### Documentation

- Explain why the viewer stopped receiving frames while both nodes were running.
- Include a screenshot of the restored connection of the rqt graph. What stayed the same and what changed?

Stop the camera and viewer with **Ctrl+C** and close the graph window when you finish.

