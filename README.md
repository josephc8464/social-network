# social-network
Creates a directed graph of users using given data in a file.

# What does it do?
The input is two user names on a row with multiple rows. The relationship between two users in this file is directed. Meaning that the first user ONLY follows the next user,
not the other way around. The goal is to create a rooted graph / tree and find the graph root by calculating the biggest in-degree from the file. We then generate the depth of the 
users in the tree by who follows who in the graph.
