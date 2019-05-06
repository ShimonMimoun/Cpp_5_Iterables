

	struct Node {
		T m_value;
		Node* m_next;
		Node(const T& v, Node* n)
			: m_value(v), m_next(n) {
		}
	};
