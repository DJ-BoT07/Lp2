import heapq

def dijkstra(graph, start):
    # Initialize the priority queue, distances, and visited set
    pq = [(0, start)]  # (distance, node)
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    visited = set()

    while pq:
        current_distance, current_node = heapq.heappop(pq)

        if current_node in visited:
            continue
        
        visited.add(current_node)

        # Update distances for each neighbor
        for neighbor, weight in graph[current_node]:
            if neighbor not in visited:
                new_distance = current_distance + weight
                if new_distance < distances[neighbor]:
                    distances[neighbor] = new_distance
                    heapq.heappush(pq, (new_distance, neighbor))

    return distances

# Example usage
graph = {
    0: [(1, 2), (3, 6)],
    1: [(0, 2), (2, 3), (3, 8)],
    2: [(1, 3), (3, 5)],
    3: [(0, 6), (1, 8), (2, 5)]
}

start_node = 0
distances = dijkstra(graph, start_node)
print("Shortest distances from node", start_node, ":", distances)
